#include "../../../include/interpretador/types/jvm_field.hpp"
#include <iostream>



JVMField::JVMField(FieldInfo* field_info):ComponentType(JVMFIELD){
  this->field_info_ref = field_info;
  this->field_name = field_info->getName();
  string field_descriptor = field_info->getDescriptor();

  // TODO: transformar descriptor em tipo certo;
  this->data = ComponentType::getDefaultValue(Int);
}

string JVMField::toString(){
  return this->field_name;
}