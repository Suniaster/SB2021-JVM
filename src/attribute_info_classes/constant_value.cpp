#include "../../include/attribute_info_classes/constant_value.hpp"

Attribute::ConstantValue::ConstantValue(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  this->class_file->setAttribute(2, this->constantvalue_index);
}

void Attribute::ConstantValue::printInfo(int n_tabs){
  AttributeInfo::printInfo(n_tabs);
  cout << createTabs(n_tabs) <<"Constant Value name index: #" << this->constantvalue_index << endl;
}