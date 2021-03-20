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
    to_return = *(float*)&this->bytes;
    return to_return;
}
