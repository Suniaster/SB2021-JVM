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

  // this->loadConstantPool();
  this->setAttribute<uint16_t>(2, this->access_flags);
  this->setAttribute<uint16_t>(2, this->this_class);
  this->setAttribute<uint16_t>(2, this->super_class);
  this->setAttribute<uint16_t>(2, this->interfaces_count);
  this->loadInterfaces();

  this->file_reader->position = 0x226;
  this->setAttribute(2, this->fields_count);
  this->loadFields();

  this->file_reader->position = 0x241;
  this->setAttribute(2, this->methods_count);
  this->loadMethods();

  this->file_reader->position = 0x31f;
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
  cout << "Interfaces: \t\t";
  cout << (int)this->interfaces_count << endl;

  cout << (int)this->fields_count << endl;

  this->printConstantPool();
  this->printMethods();
  
  AttributeInfo::printAttributes(this->attributes);
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