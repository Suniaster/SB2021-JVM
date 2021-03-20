#include "../../include/constant_pool_classes/long_info.hpp"



CP::LongInfo::LongInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 5;
}

void CP::LongInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->high_bytes);
  this->class_file->setAttribute<uint32_t>(4, this->low_bytes);
}

void CP::LongInfo::printInfo(){
  cout << "\tLong: High Bytes " << this->high_bytes << endl;
  cout << "\tLong:  Low Bytes " << this->low_bytes << endl;
  cout << "\tLong: Value " << dec << this->returnLong() << endl;
}

long long CP::LongInfo::returnLong(){
  signed long long to_return;
  to_return = (signed long long)(((unsigned long long) this->high_bytes << 32) | (unsigned long long)this->low_bytes);
  return to_return;
}
string CP::LongInfo::toString(){
  return std::to_string(this->returnLong());
}
