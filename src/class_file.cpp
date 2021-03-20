#include "../include/class_file.hpp"
#include "../include/cp_info.hpp"


#include "../include/attribute_info.hpp"

#include "../include/constant_pool_classes/utf8_info.hpp"

ClassFile::ClassFile(string file_name){
  file_reader = new FileReader();
  file_reader->readFile(file_name);
}

void ClassFile::loadClass(){
  this->setAttribute<uint32_t>(4, this->magic_number);
  this->setAttribute<uint16_t>(2, this->minor_version);
  this->setAttribute<uint16_t>(2, this->major_version);
  this->setAttribute<uint16_t>(2, this->constant_pool_count);
  this->loadConstantPool();

  this->file_reader->position = 0x227;
  this->setAttribute(2, this->fields_count);
  this->loadFields();

  this->file_reader->position = 0x31f;

  this->setAttribute<uint16_t>(2, this->attributes_count);
  AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this);
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl;
  cout << (int)this->minor_version << endl;
  cout << (int)this->major_version << endl;
  cout << (int)this->constant_pool_count << endl;
  cout << (int)this->fields_count << endl;

  this->printConstantPool();
  this->printFields();
  AttributeInfo::printAttributes(this->attributes);
}

void ClassFile::printConstantPool(){
    cout << "******************** Constant Pool ********************" << endl;
    cout << "[hex] [dec]" << endl;
    for (int i = 0; i < this->constant_pool_count - 1; i++) {
        cout << hex << "[" << i + 1 << "] ";
        cout << dec << "[" << i + 1 << "]" << endl;
        this->constant_pool[i]->printInfo();
    }
}

void ClassFile::loadConstantPool(){
  uint8_t tag = 0;
  CpInfo* cp_info;

  for(int i=0; i< this->constant_pool_count - 1;i++){
    // Le tag
    this->setAttribute<uint8_t>(1, tag);


    // instanciar classe certa
    cp_info = CpInfo::getInstance(tag, this);



    // seta atributos
    cp_info->setInfo();

    // salva na classe
    this->constant_pool.push_back(cp_info);

    // adiciona espaço inutilizável caso tenha um long ou double
    if (tag == 0x5 || tag == 0x6) {
        this->constant_pool.push_back(cp_info->returnUnusableSpace(this));
    }
  }
}

void ClassFile::loadFields() {
  FieldInfo* field;

  for (int i=0; i<this->fields_count; i++) {
    field = new FieldInfo(this);
    this->fields.push_back(field);
  }
}

void ClassFile::printFields() {
  cout << "********************  Fields Info ********************" << endl;
  cout << "Fields count:" << dec << (int)this->fields_count << endl;

  for(unsigned int i=0; i<this->fields_count; i++){
    cout << "[" << i << "]";
    this->fields[i]->printInfo();
  }
}

CpInfo * ClassFile::getConstantPoolEntry(int index){
  return this->constant_pool[index- 1];
}

string ClassFile::getConstantPoolUtf8String(int index){
  // TODO: Codar um throw pra caso indice nao corresponda a UTf8
  CP::Utf8Info *utf_info = (CP::Utf8Info *)this->constant_pool[index-1];
  return utf_info->returnString();
}

string ClassFile::beautifiedMajorVersion() {
  switch (this->major_version) {
    case 46:
      return "1.2";

    case 47:
      return "1.3";

    case 48:
      return "1.4";

    case 49:
      return "1.5";

    case 50:
      return "1.6";

    case 51:
      return "1.7";

    case 52:
      return "1.8";

    case 53:
      return "1.9";

    case 54:
      return "1.10";

    case 55:
      return "1.11";

    case 56:
      return "1.12";

    case 57:
      return "1.13";
    default:
      throw runtime_error("File version not supported.");
  }
}

string ClassFile::beautifiedAccessFlags(uint16_t access_flag, bool is_fields) {
  map <int,string> accesses;
  string beautified;

  accesses[0x0001] = "public";
  accesses[0x0002] = "private";
  accesses[0x0004] = "protected";
  accesses[0x0008] = "static";
  accesses[0x0010] = "final";
  accesses[0x0020] = "synchronized";

  if (is_fields) {
    accesses[0x0040] = "volatile";
    accesses[0x0080] = "transient";
  }
  else {
    accesses[0x0040] = "bridge";
    accesses[0x0080] = "varargs";
  }

  accesses[0x0100] = "native";
  accesses[0x0200] = "interface";
  accesses[0x0400] = "abstract";
  accesses[0x0800] = "strictfp";
  accesses[0x1000] = "synthetic";
  accesses[0x4000] = "enum";

  for ( const auto &access: accesses) {
    if (access_flag & access.first)
      beautified.append(access.second + " ");
  }

  return beautified;
}