#include "../../include/constant_pool_classes/double_info.hpp"



CP::DoubleInfo::DoubleInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 6;
}

void CP::DoubleInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->high_bytes);
  this->class_file->setAttribute<uint32_t>(4, this->low_bytes);
}

void CP::DoubleInfo::printInfo(){
  cout << "Double: High Bytes " << hex << this->high_bytes << endl;
  cout << "Double:  Low Bytes " << hex << this->low_bytes << endl;
  cout << "Double: Value " << this->returnDouble() << endl;
}

double CP::DoubleInfo::returnDouble(){
  double to_return;
  to_return = (double) ((uint64_t)this->high_bytes << 32) + (uint64_t) this->low_bytes;
  return (double)to_return;
}
