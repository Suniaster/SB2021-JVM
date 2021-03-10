#include "../../include/constant_pool_classes/method_type_info.hpp"



CP::MethodTypeInfo::MethodTypeInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 16;
}

void CP::MethodTypeInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->class_index);
  this->class_file->setAttribute<uint16_t>(2, this->descriptor_index);
}

void CP::MethodTypeInfo::printInfo(){
  cout << "MethodType: CI " << this->class_index << endl;
  cout << "MethodType: DI " << this->descriptor_index << endl;
}