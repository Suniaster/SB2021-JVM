#include "../include/class_file.hpp"
#include "../include/cp_info.hpp"

#include "../include/attribute_info.hpp"

#include "../include/constant_pool_classes/utf8_info.hpp"

ClassFile::ClassFile(string file_name)
{
  file_reader = new FileReader();
  file_reader->readFile(file_name);
}

void ClassFile::loadClass()
{
  this->setAttribute<uint32_t>(4, this->magic_number);
  this->setAttribute<uint16_t>(2, this->minor_version);
  this->setAttribute<uint16_t>(2, this->major_version);
  this->setAttribute<uint16_t>(2, this->constant_pool_count);
  this->loadConstantPool();

  this->setAttribute<uint16_t>(2, this->access_flags);
  this->setAttribute<uint16_t>(2, this->this_class);
  this->setAttribute<uint16_t>(2, this->super_class);
  this->setAttribute<uint16_t>(2, this->interfaces_count);
  this->loadInterfaces();

  this->setAttribute(2, this->fields_count);
  this->loadFields();

  this->setAttribute(2, this->methods_count);
  this->loadMethods();

  this->setAttribute<uint16_t>(2, this->attributes_count);
  AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this);
}

void ClassFile::printClass()
{
  CpInfo *temp;
  cout << "******************** General Information ********************" << endl;
  cout << "Magic number: \t\t";
  cout << hex << this->magic_number << endl;
  cout << "Minor version: \t\t";
  cout << (int)this->minor_version << endl;
  cout << "Major version: \t\t";
  cout << (int)this->major_version << endl;
  cout << "Constant pool count: \t";
  cout << dec << (int)this->constant_pool_count << endl;
  cout << "Access flags: \t\t";
  cout << hex << (int)this->access_flags << endl;
  cout << "This class: \t\tcpinfo #";
  temp = this->getConstantPoolEntry(this->this_class);
  cout << dec << (int)this->this_class << " " << temp->toString() << endl;
  cout << "Super class: \t\tcpinfo #";
  temp = this->getConstantPoolEntry(this->super_class);
  cout << dec << (int)this->super_class << " " << temp->toString() << endl;
  cout << "Interfaces count: \t\t";
  cout << (int)this->interfaces_count << endl;
  cout << "Fields Count: \t\t";
  cout << (int)this->fields_count << endl;
  cout << "Methods count: \t\t";
  cout << (int)this->methods_count << endl;
  cout << "Attributes count: \t\t";
  cout << (int)this->attributes_count << endl;

  this->printConstantPool();
  this->printInterfaces();
  this->printFields();
  this->printMethods();
  AttributeInfo::printAttributes(this->attributes, 0);
}

void ClassFile::printConstantPool()
{
  cout << "******************** Constant Pool ********************" << endl;
  cout << "[hex] [dec]" << endl;
  for (int i = 0; i < this->constant_pool_count - 1; i++)
  {
    cout << hex << "[" << i + 1 << "] ";
    cout << dec << "[" << i + 1 << "]" << endl;
    this->constant_pool[i]->printInfo();
  }
}

void ClassFile::loadConstantPool()
{
  uint8_t tag = 0;
  CpInfo *cp_info;

  for (int i = 0; i < this->constant_pool_count - 1; i++)
  {
    // Le tag
    this->setAttribute<uint8_t>(1, tag);

    // instanciar classe certa
    cp_info = CpInfo::getInstance(tag, this);

    // seta atributos
    cp_info->setInfo();

    // salva na classe
    this->constant_pool.push_back(cp_info);

    // adiciona espaço inutilizável caso tenha um long ou double
    if (tag == 0x5 || tag == 0x6)
    {
      this->constant_pool.push_back(cp_info->returnUnusableSpace(this));
    }
  }
}

void ClassFile::loadInterfaces()
{
  InterfaceInfo *interface;

  for (int i = 0; i < this->interfaces_count; i++)
  {
    interface = new InterfaceInfo(this);
    this->interfaces.push_back(interface);
  }
}

void ClassFile::loadFields()
{
  FieldInfo *field;

  for (int i = 0; i < this->fields_count; i++)
  {
    field = new FieldInfo(this);
    this->fields.push_back(field);
  }
}

void ClassFile::printInterfaces()
{
  cout << endl
       << "----- Interfaces Array  -----" << endl;

  for (unsigned int i = 0; i < this->interfaces_count; i++)
  {
    cout << "[" << i << "]";
    this->interfaces[i]->printInfo();
  }
}

void ClassFile::printFields()
{
  cout << endl
       << "----- Fields Info  -----" << endl;

  for (unsigned int i = 0; i < this->fields.size(); i++)
  {
    cout << "[" << i << "]";
    this->fields[i]->printInfo();
  }
}


void ClassFile::loadMethods() {
  MethodInfo* method;

  for(int i=0; i<this->methods_count; i++) {
    method = new MethodInfo(this);
    this->methods.push_back(method);
  }
}

void ClassFile::printMethods() {
  cout << endl << "----- Methods Info  -----" << endl;

  for (unsigned int i=0; i<this->methods.size(); i++) {
    cout << "[" << i << "]";
    this->methods[i]->printInfo();
  }
}

CpInfo * ClassFile::getConstantPoolEntry(int index){
  return this->constant_pool[index- 1];
}

string ClassFile::getConstantPoolUtf8String(int index)
{
  // TODO: Codar um throw pra caso indice nao corresponda a UTf8
  CP::Utf8Info *utf_info = (CP::Utf8Info *)this->constant_pool[index - 1];
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