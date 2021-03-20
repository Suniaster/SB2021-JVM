#include "../../include/constant_pool_classes/float_info.hpp"



CP::FloatInfo::FloatInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 4;
}

void CP::FloatInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->bytes);
}

void CP::FloatInfo::printInfo(){
  cout << "\tFloat: Bytes " << hex <<  this->bytes << endl;
  cout << "\tFloat: Value " << fixed <<  this->returnFloat() << endl;
}

float CP::FloatInfo::returnFloat(){
    float to_return;
    int s = ((this->bytes >> 31) == 0) ? 1 : -1;
    int e = ((this->bytes >> 23) & 0xff);
    int m = (e == 0) ?  (this->bytes & 0x7fffff) << 1 :(this->bytes & 0x7fffff) | 0x800000;
    to_return = s * m * (2^(e-150));
    return to_return;
}
