#include "../../include/constant_pool_classes/double_info.hpp"



CP::DoubleInfo::DoubleInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 6;
}

void CP::DoubleInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->high_bytes);
  this->class_file->setAttribute<uint32_t>(4, this->low_bytes);
}

void CP::DoubleInfo::printInfo(){
  cout << "Double: High Bytes " << this->high_bytes << endl;
  cout << "Double:  Low Bytes" << this->low_bytes << endl;
}

double CP::DoubleInfo::returnDouble(){
  double to_return;
  to_return = ((long) this->high_bytes << 32) + (long) this->low_bytes;
  return (double)to_return;
}
