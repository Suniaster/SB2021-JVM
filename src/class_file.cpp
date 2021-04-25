#include "../include/class_file.hpp"
#include "../include/cp_info.hpp"

#include "../include/attribute_info.hpp"

#include "../include/constant_pool_classes/utf8_info.hpp"

ClassFile::ClassFile(string class_name)
{
  file_reader = new FileReader();
  file_reader->readFile(class_name);
  this->state = READ;
  this->heap_ref = -1;
}

ClassFile::~ClassFile() {
  this->deleteVector<CpInfo*>(this->constant_pool);
  this->deleteVector<FieldInfo*>(this->fields);
  this->deleteVector<MethodInfo*>(this->methods);
  this->deleteVector<AttributeInfo*>(this->attributes);
  this->deleteVector<InterfaceInfo*>(this->interfaces);
  delete this->file_reader;
}

void ClassFile::loadClass()
{
  this->setAttribute<uint32_t>(4, this->magic_number);
  if (this->magic_number != 0xcafebabe) {
      throw std::invalid_argument("Wrong magic number");
  }
  this->setAttribute<uint16_t>(2, this->minor_version);
  if (this->minor_version != 0) {
      throw std::invalid_argument("Invalid minor version");
  }
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
  this->state = LOADED;
}

void ClassFile::printClass()
{
  CpInfo *temp;
  cout << "\n******************** General Information ********************" << endl;
  cout << "Magic number:         ";
  cout << hex << this->magic_number << endl;
  cout << "Minor version:        ";
  cout << (int)this->minor_version << endl;
  cout << "Major version:        ";
  cout << dec << (int)this->major_version << " " << beautifiedMajorVersion() << endl;
  cout << "Constant pool count:  ";
  cout << dec << (int)this->constant_pool_count << endl;
  cout << "Access flags:         ";
  cout << hex << "0x"<< (int)this->access_flags << " "<< beautifiedAccessFlags(this->access_flags, false, false) << endl;
  cout << "This class:           cpinfo #";
  temp = this->getConstantPoolEntry(this->this_class);
  cout << dec << (int)this->this_class << " " << temp->toString() << endl;
  cout << "Super class:          cpinfo #";
  temp = this->getConstantPoolEntry(this->super_class);
  cout << dec << (int)this->super_class << " " << temp->toString() << endl;
  cout << "Interfaces count:     ";
  cout << (int)this->interfaces_count << endl;
  cout << "Fields Count:         ";
  cout << (int)this->fields_count << endl;
  cout << "Methods count:        ";
  cout << (int)this->methods_count << endl;
  cout << "Attributes count:     ";
  cout << (int)this->attributes_count << endl;

  this->printConstantPool();
  this->printInterfaces();
  this->printFields();
  this->printMethods();

  cout << "\n******************** Attributes Info ************************" << endl;
  AttributeInfo::printAttributes(this->attributes, 0);
}

void ClassFile::printConstantPool()
{
  cout << "\n******************** Constant Pool **************************" << endl;
  cout << "[hex] [dec]" << endl;
  for (int i = 0; i < this->constant_pool_count - 1; i++)
  {
    cout << hex << "[" << i + 1 << "]";
    cout << dec << " [" << i + 1 << "]" << endl;
    this->constant_pool[i]->printInfo();
  }
}

void ClassFile::loadConstantPool()
{
  uint8_t tag = 0;
  CpInfo *cp_info;

  for (int i = 0; i < this->constant_pool_count - 1; i++)
  {
    this->setAttribute<uint8_t>(1, tag);

    cp_info = CpInfo::getInstance(tag, this);
    cp_info->setInfo();
    this->constant_pool.push_back(cp_info);

    // adiciona espaço inutilizável caso tenha um long ou double
    if (tag == 0x5 || tag == 0x6)
    {
      this->constant_pool.push_back(cp_info->returnUnusableSpace(this));
      i++;
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
  cout << "\n******************** Interface Array ************************" << endl;

  for (unsigned int i = 0; i < this->interfaces_count; i++)
  {
    cout << "[" << i << "]" << endl;
    this->interfaces[i]->printInfo();
  }
}

void ClassFile::printFields()
{
  cout << "\n******************** Fields Info ****************************" << endl;

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
  cout << "\n******************** Methods Info ***************************" << endl;

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

string ClassFile::getSuperClassName(){
  if(this->super_class == 0) return "invalid constant pool reference";
  return this->getConstantPoolEntry(this->super_class)->toString();
}

string ClassFile::getThisClassName(){
  return this->getConstantPoolEntry(this->this_class)->toString();
}
string ClassFile::beautifiedMajorVersion() {
  switch (this->major_version) {
    case 46:
      return "[1.2]";

    case 47:
      return "[1.3]";

    case 48:
      return "[1.4]";

    case 49:
      return "[1.5]";

    case 50:
      return "[1.6]";

    case 51:
      return "[1.7]";

    case 52:
      return "[1.8]";

    case 53:
      return "[1.9]";

    case 54:
      return "[1.10]";

    case 55:
      return "[1.11]";

    case 56:
      return "[1.12]";

    case 57:
      return "[1.13]";
    default:
      throw runtime_error("File version not supported.");
  }
}



string ClassFile::beautifiedAccessFlags(uint16_t access_flags, bool is_fields, bool is_methods) {
  map <int,string> flags;
  string beautified;

  flags[0x0001] = "public";
  flags[0x0002] = "private";
  flags[0x0004] = "protected";
  flags[0x0008] = "static";
  flags[0x0010] = "final";

  if (is_methods)
    flags[0x0020] = "synchronized";
  else 
    flags[0x0020] = "super";

  if (is_fields) {
    flags[0x0040] = "volatile";
    flags[0x0080] = "transient";
  }
  else {
    flags[0x0040] = "bridge";
    flags[0x0080] = "varargs";
  }

  flags[0x0100] = "native";
  flags[0x0200] = "interface";
  flags[0x0400] = "abstract";
  flags[0x0800] = "strictfp";
  flags[0x1000] = "synthetic";
  flags[0x4000] = "enum";

  for ( const auto &flag: flags) {
    if (access_flags & flag.first)
      beautified.append(flag.second + " ");
  }

  return "[" + beautified.erase(beautified.find_last_not_of(" ") + 1) + "]";
}
