#include "../../include/constant_pool_classes/name_and_type_info.hpp"



CP::NameAndTypeInfo::NameAndTypeInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 12;
}

void CP::NameAndTypeInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->name_index);
  this->class_file->setAttribute<uint16_t>(2, this->descriptor_index);
}

void CP::NameAndTypeInfo::printInfo(){
  cout << "Name and Type: NI " << this->name_index << endl;
  cout << "Name and Type: DI " << this->descriptor_index << endl;
}
