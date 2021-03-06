#include "../../include/constant_pool_classes/long_info.hpp"



CP::LongInfo::LongInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 5;
}

void CP::LongInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->high_bytes);
  this->class_file->setAttribute<uint32_t>(4, this->low_bytes);
}

void CP::LongInfo::printInfo(){
  cout << "Long: High Bytes " << this->high_bytes << endl;
  cout << "Long:  Low Bytes" << this->low_bytes << endl;
}

long CP::LongInfo::returnLong(){
  long to_return;
  to_return = ((long) this->high_bytes << 32) + (long) this->low_bytes;
  return to_return;
}
