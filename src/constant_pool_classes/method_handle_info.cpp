#include "../../include/constant_pool_classes/method_handle_info.hpp"



CP::MethodHandleInfo::MethodHandleInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 15;
}

void CP::MethodHandleInfo::setInfo(){
   // TODO checar se os valores de kind e index são válidos
  this->class_file->setAttribute<uint8_t>(1, this->reference_kind);
  this->class_file->setAttribute<uint16_t>(2, this->reference_index);
}

void CP::MethodHandleInfo::printInfo(){
  cout << "MethodHandle: RK " << this->reference_kind << endl;
  cout << "MethodHandle: RI " << this->reference_index << endl;
}
