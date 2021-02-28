#include "../../include/attribute_info_classes/source_file.hpp"

Attribute::SourceFile::SourceFile(ClassFile *class_file, 
  uint16_t attribute_name_index, 
  uint32_t attribute_length)
    :AttributeInfo(
      class_file, 
      attribute_name_index, 
      attribute_length)
  {
}

void Attribute::SourceFile::setInfo(){
  this->class_file->setAttribute(2, this->sourcefile_index);
}

void Attribute::SourceFile::printInfo(){
  AttributeInfo::printInfo();
  cout << "\tSource file name index: #" << this->sourcefile_index;
  cout << " <" << this->getFileName() << ">" << endl;
}

string Attribute::SourceFile::getFileName(){
  // TODO: puxar o nome correto da constant pool
  return "test.java";
}