#include "../../include/constant_pool_classes/field_ref_info.hpp"



CP::FieldRefInfo::FieldRefInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 9;
}

void CP::FieldRefInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->class_index);
  this->class_file->setAttribute<uint16_t>(2, this->name_and_type_index);
}

void CP::FieldRefInfo::printInfo(){
  cout << "\tFieldRef: CI " << this->class_index << endl;
  cout << "\tFieldRef: NTI " << this->name_and_type_index << endl;
}
