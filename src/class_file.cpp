#include "../include/class_file.hpp"
#include "../include/cp_info.hpp"
#include "../include/constant_pool_classes/method_ref_info.hpp"

#include "../include/attribute_info.hpp"

ClassFile::ClassFile(string file_name){
  file_reader = new FileReader();
  file_reader->readFile(file_name);
}

void ClassFile::loadClass(){
  this->setAttribute<uint32_t>(4, this->magic_number);
  this->setAttribute<uint16_t>(2, this->minor_version);
  this->setAttribute<uint16_t>(2, this->major_version);
  this->setAttribute<uint16_t>(2, this->constant_pool_count);

  // this->loadConstantPool();
  this->file_reader->position = 0x226;
  this->setAttribute(2, this->fields_count);
  this->loadFields();
  this->setAttribute<uint16_t>(2, this->attributes_count);
  AttributeInfo::loadAttributes(this->attributes, 1, this);
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl; 
  cout << (int)this->minor_version << endl; 
  cout << (int)this->major_version << endl; 
  cout << (int)this->constant_pool_count << endl;
  cout << (int)this->fields_count << endl;

  AttributeInfo::printAttributes(this->attributes);
}



void ClassFile::loadConstantPool(){
  uint8_t tag;
  CpInfo* cp_info;

  // TODO: TROCAR PRO NUMERO CERTO
  for(int i=0; i< 2;i++){
    // Le tag
    tag = 0;
    this->setAttribute<uint8_t>(1, tag);

    // instanciar classe certa
    cp_info = CpInfo::getInstance(tag, this);

    // seta atributos
    cp_info->setInfo();
    // cp_info->printInfo();

    // salva na classe
    this->constant_pool.push_back(cp_info);
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
  cout << endl << "----- Fields Info  -----" << endl;

  for(unsigned int i=0; i<this->fields.size(); i++){
    cout << "[" << i << "]";
    this->fields[i]->printInfo();
  }
}