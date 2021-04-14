#include "../../include/constant_pool_classes/double_info.hpp"



CP::DoubleInfo::DoubleInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 6;
}

void CP::DoubleInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->high_bytes);
  this->class_file->setAttribute<uint32_t>(4, this->low_bytes);
}

void CP::DoubleInfo::printInfo(){
  cout << "\tDouble: High Bytes " << hex << this->high_bytes << endl;
  cout << "\tDouble:  Low Bytes " << hex << this->low_bytes << endl;
  cout << "\tDouble: Value " << fixed <<this->returnDouble() << endl;
}

uint64_t CP::DoubleInfo::getValue(){
  
  return ((uint64_t)this->high_bytes << 32) + (uint64_t) this->low_bytes;
}

double CP::DoubleInfo::returnDouble(){
  double to_return;
  uint64_t bits = ((uint64_t)this->high_bytes << 32) + (uint64_t) this->low_bytes;
  to_return = *(double*)&bits;
  return to_return;
}
string CP::DoubleInfo::toString(){
  return std::to_string(this->returnDouble());
}
