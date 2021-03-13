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

double CP::DoubleInfo::returnDouble(){
  double to_return;
  uint64_t bits = ((uint64_t)this->high_bytes << 32) + (uint64_t) this->low_bytes;
  int s = ((bits >> 63) == 0) ? 1 : -1;
  int e = (int)((bits >> 52) & 0x7ffL);
  long m = (e == 0) ? ((bits & 0xfffffffffffffL) << 1) : ((bits & 0xfffffffffffffL) | 0x10000000000000L);
  to_return = s * m * (2^(e-1075));
  return to_return;
}
