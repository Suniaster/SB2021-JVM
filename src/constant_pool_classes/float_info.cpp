#include "../../include/constant_pool_classes/float_info.hpp"



CP::FloatInfo::FloatInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 4;
}

void CP::FloatInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->bytes);
}

void CP::FloatInfo::printInfo(){
  cout << "float: NI " << this->bytes << endl;

}

float CP::FloatInfo::returnFloat(){
    return (float) this->bytes;
}
