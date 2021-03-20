#include "../include/attribute_info.hpp"

#include "../include/attribute_info_classes/source_file.hpp"
#include "../include/attribute_info_classes/general_info.hpp"
#include "../include/attribute_info_classes/constant_value.hpp"
#include "../include/attribute_info_classes/code_attribute.hpp"
#include "../include/attribute_info_classes/exceptions.hpp"
#include "../include/attribute_info_classes/inner_classes.hpp"
#include "../include/attribute_info_classes/synthetic.hpp"

#include "../include/constant_pool_classes/utf8_info.hpp"

AttributeInfo::AttributeInfo(Attribute::AttrInitialValue initial_value){
  this->class_file = initial_value.class_file;
  this->attribute_name_index = initial_value.attribute_name_index;
  this->attribute_length = initial_value.attribute_length;
}

string AttributeInfo::getAttributeName(){
  return this->class_file->getConstantPoolUtf8String(this->attribute_name_index);
}

string AttributeInfo::createTabs(int n_tabs){
  string returnString = "";
  for(int i=0;i<n_tabs;i++) returnString += "\t";
  return returnString;
}

void AttributeInfo::printInfo(int n_tabs){
  cout << dec;
  cout << "\tAttribute name index: \t#" << this->attribute_name_index;
  cout << " <" << this->getAttributeName() << ">" << endl;
  cout << createTabs(n_tabs) << "Attribute length: \t" << this->attribute_length << endl;
}

void AttributeInfo::loadAttributes(vector<AttributeInfo*> &attributes, uint16_t size, ClassFile* class_file){
  AttributeInfo* attr;

  for(int i=0; i<size; i++){
    attr = AttributeInfo::getInstance(class_file);
    attributes.push_back(attr);
  }
}

void AttributeInfo::printAttributes(vector<AttributeInfo*> attributes, int n_tabs) {
  for (unsigned int i = 0; i < attributes.size(); i += 1) {
    cout << createTabs(n_tabs) << "[" << i << "]";
    attributes[i]->printInfo(n_tabs);
  }
}

AttributeInfo* AttributeInfo::getInstance(ClassFile* class_file){
  uint16_t attr_name_index;
  uint32_t attr_length;

  class_file->file_reader->readBytes(2, attr_name_index);
  class_file->file_reader->readBytes(4, attr_length);
  Attribute::AttrInitialValue params = {class_file, attr_name_index, attr_length};

  string attr_name= class_file->getConstantPoolUtf8String(attr_name_index);
  if(attr_name == "SourceFile"){
    return new Attribute::SourceFile(params);
  }
  if(attr_name == "ConstantValue"){
    return new Attribute::ConstantValue(params);
  }
  if(attr_name == "Code"){
    return new Attribute::CodeAttribute(params);
  }
  if(attr_name == "Exceptions"){
    return new Attribute::Exceptions(params);
  }
  if(attr_name == "InnerClasses"){
    return new Attribute::InnerClasses(params);
  }
  if(attr_name == "Synthetic"){
    return new Attribute::Synthetic(params);
  }
  
  return new Attribute::GeneralInfo(params);
}