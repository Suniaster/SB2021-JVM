#include "../../include/attribute_info_classes/general_info.hpp"

Attribute::GeneralInfo::GeneralInfo(ClassFile *class_file, 
  uint16_t attribute_name_index, 
  uint32_t attribute_length)
    :AttributeInfo(
      class_file, 
      attribute_name_index, 
      attribute_length)
  {
}

void Attribute::GeneralInfo::setInfo(){
  uint8_t byte_read;
  for(unsigned int i=0; i< this->attribute_length; i+=1){
    byte_read = 0;
    this->class_file->setAttribute(1, byte_read);
    this->info.push_back(byte_read);
  }
}

void Attribute::GeneralInfo::printInfo(){
  AttributeInfo::printInfo();
}