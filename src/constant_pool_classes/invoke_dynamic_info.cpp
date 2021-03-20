#include "../../include/constant_pool_classes/invoke_dynamic_info.hpp"



CP::InvokeDynamicInfo::InvokeDynamicInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 18;
}

void CP::InvokeDynamicInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->bootstrap_method_attr_index);
  this->class_file->setAttribute<uint16_t>(2, this->name_and_type_index);
}

void CP::InvokeDynamicInfo::printInfo(){
  cout << "\tInterfaceMethodRef: Bootstrap Method Index " << this->bootstrap_method_attr_index << endl;
  cout << "\tInterfaceMethodRef: Nane and Type Index" << this->name_and_type_index << endl;
  cout << "\n";
  CpInfo* name_and_type_info = this->class_file->getConstantPoolEntry((int)this->name_and_type_index);
  name_and_type_info->printInfo();
}
