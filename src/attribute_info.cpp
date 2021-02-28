#include "../include/attribute_info.hpp"
#include "../include/attribute_info_classes/source_file.hpp"
#include "../include/attribute_info_classes/general_info.hpp"

AttributeInfo::AttributeInfo(
    ClassFile *class_file, 
    uint16_t attribute_name_index, 
    uint32_t attribute_length){
  this->class_file = class_file;
  this->attribute_name_index = attribute_name_index;
  this->attribute_length = attribute_length;
}

string AttributeInfo::getAttributeName(){
  //** TODO: Usar constant pool pra achar nome certo
  return "SourceFile";
}

void AttributeInfo::printInfo(){
  cout << dec;
  cout << "\tAttribute name index: \t#" << this->attribute_name_index;
  cout << " <" << this->getAttributeName() << ">" << endl;
  cout << "\tAttribute length: \t" << this->attribute_length << endl;
}


AttributeInfo* AttributeInfo::getInstance(
  ClassFile* class_file,
  uint16_t attr_name_index,
  uint32_t attr_length
  ){
  // Todo: pegar nome correto da cosntantPool
  string attr_name="SourceFile";
  AttributeInfo* attr_read;

  if(attr_name == "SourceFile"){
    attr_read = new Attribute::SourceFile(class_file, attr_name_index, attr_length);
  }
  else{
    attr_read = new Attribute::GeneralInfo(class_file, attr_name_index, attr_length);
  }
  return attr_read;
}