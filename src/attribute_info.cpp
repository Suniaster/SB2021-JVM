#include "../include/attribute_info.hpp"

#include "../include/attribute_info_classes/source_file.hpp"
#include "../include/attribute_info_classes/general_info.hpp"
#include "../include/attribute_info_classes/constant_value.hpp"

AttributeInfo::AttributeInfo(Attribute::AttrInitialValue initial_value){
  this->class_file = initial_value.class_file;
  this->attribute_name_index = initial_value.attribute_name_index;
  this->attribute_length = initial_value.attribute_length;
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

void AttributeInfo::loadAttributes(vector<AttributeInfo*> attributes, uint16_t size, ClassFile* class_file){
  AttributeInfo* attr;

  for(int i=0; i<size; i++){
    attr = AttributeInfo::getInstance(class_file);
    attr->setInfo();
    attributes.push_back(attr);
  }
}

void AttributeInfo::printAttributes(vector<AttributeInfo*> attributes) {
  cout << endl << "----- Attributes Info  -----" << endl;
  for (unsigned int i = 0; i < attributes.size(); i += 1) {
    cout << "[" << i << "]";
    attributes[i]->printInfo();
  }
}

AttributeInfo* AttributeInfo::getInstance(ClassFile* class_file){
  uint16_t attr_name_index;
  uint32_t attr_length;
  AttributeInfo* attr_read;

  class_file->file_reader->readBytes(2, attr_name_index);
  class_file->file_reader->readBytes(4, attr_length);
  Attribute::AttrInitialValue params = {class_file, attr_name_index, attr_length};
  // Todo: pegar nome correto da cosntantPool
  string attr_name="Suamae";

  if(attr_name == "SourceFile"){
    attr_read = new Attribute::SourceFile(params);
  }
  if(attr_name == "ConstantValue"){
    attr_read = new Attribute::ConstantValue(params);
  }
  else{
    attr_read = new Attribute::GeneralInfo(params);
  }
  return attr_read;
}