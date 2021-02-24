#include "../include/class_file.hpp"

ClassFile::ClassFile(string file_name){
  file_reader = new FileReader();
  file_reader->readFile(file_name);
}

void ClassFile::loadClass(){
  this->setAttribute<uint32_t>(4, this->magic_number);
  this->setAttribute<uint16_t>(2, this->minor_version);
  this->setAttribute<uint16_t>(2, this->major_version);
  this->setAttribute<uint16_t>(2, this->constant_pool_count);
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl; 
  cout << (int)this->minor_version << endl; 
  cout << (int)this->major_version << endl; 
  cout << (int)this->constant_pool_count << endl;
}
