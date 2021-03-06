#include "../../include/attribute_info_classes/constant_value.hpp"

Attribute::ConstantValue::ConstantValue(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  this->class_file->setAttribute(2, this->constantvalue_index);
}

void Attribute::ConstantValue::setInfo(){}

void Attribute::ConstantValue::printInfo(){
  AttributeInfo::printInfo();
  cout << "\tConstant Value name index: #" << this->constantvalue_index << endl;
}