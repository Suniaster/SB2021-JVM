#include "../../include/constant_pool_classes/interface_method_ref_info.hpp"



CP::InterfaceMethodRefInfo::InterfaceMethodRefInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 11;
}

void CP::InterfaceMethodRefInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->class_index);
  this->class_file->setAttribute<uint16_t>(2, this->name_and_type_index);
}

void CP::InterfaceMethodRefInfo::printInfo(){
  cout << "\tInterfaceMethodRef: CI " << this->class_index << endl;
  cout << "\tInterfaceMethodRef: NTI " << this->name_and_type_index << endl;
}
