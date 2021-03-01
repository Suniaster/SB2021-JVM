#include "../include/class_file.hpp"
#include "../include/cp_info.hpp"
#include "../include/constant_pool_classes/method_ref_info.hpp"

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
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl;
  cout << (int)this->minor_version << endl;
  cout << (int)this->major_version << endl;
  cout << (int)this->constant_pool_count << endl;
  this->printConstantPool();
}

void ClassFile::printConstantPool(){
    for (int i = 0; i < this->constant_pool_count - 1; i++) {
        this->constant_pool[i]->printInfo();
    }
}

void ClassFile::loadConstantPool(){
  uint8_t tag;
  CpInfo* cp_info;


  for(int i=0; i< this->constant_pool_count - 1;i++){
    // Le tag
    tag = 0;
    this->setAttribute<uint8_t>(1, tag);

    // instanciar classe certa
    cp_info = CpInfo::getInstance(tag, this);

    // seta atributos
    cp_info->setInfo();

    // salva na classe
    this->constant_pool.push_back(cp_info);
  }
}
