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
  this->file_reader->position = 0x17d;
  this->setAttribute<uint16_t>(2, this->attributes_count);
  this->loadAttributes();
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl; 
  cout << (int)this->minor_version << endl; 
  cout << (int)this->major_version << endl; 
  cout << (int)this->constant_pool_count << endl;

  this->printAttributes();
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

void ClassFile::loadAttributes(){
  uint16_t attr_name_i;
  uint32_t attr_len;
  AttributeInfo* attr;

  cout << "Attr count " << this->attributes_count << endl;
  for(int i=0;i<1;i+=1){
    attr_name_i = 0;
    attr_len    = 0;

    this->setAttribute(2, attr_name_i);
    this->setAttribute(4, attr_len);
    attr = AttributeInfo::getInstance(this, attr_name_i, attr_len);
    attr->setInfo();
    this->attributes.push_back(attr);
  }
}

void ClassFile::printAttributes(){
  AttributeInfo* attribute;
  cout << endl << "----- Attributes Info  -----" << endl;
  for(unsigned int i=0;i<this->attributes.size();i+=1){
    attribute = this->attributes[i];
    cout << "[" << i << "]";
    attribute->printInfo();
  }
}