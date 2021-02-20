#include "../include/class_file.hpp"

ClassFile::ClassFile(string file_name){
  file_reader = new FileReader();
  file_reader->readFile(file_name);
}

void ClassFile::loadClass(){
  this->setMagic();
}

void ClassFile::printClass(){
  cout << hex << this->magic_number << endl; 
}

void ClassFile::setMagic(){
  vector<BYTE> magic_bytes = this->file_reader->getBytes(4);
  this->magic_number = this->file_reader->vectorTo4Bytes(magic_bytes);
}