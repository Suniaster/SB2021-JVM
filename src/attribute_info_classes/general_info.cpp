#include "../../include/attribute_info_classes/general_info.hpp"

Attribute::GeneralInfo::GeneralInfo(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  uint8_t byte_read;
  for(unsigned int i=0; i< this->attribute_length; i+=1){
    byte_read = 0;
    this->class_file->setAttribute(1, byte_read);
    this->info.push_back(byte_read);
  }
}

void Attribute::GeneralInfo::printInfo(int n_tabs){
  AttributeInfo::printInfo(n_tabs);
}