#include "../../include/attribute_info_classes/source_file.hpp"

Attribute::SourceFile::SourceFile(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
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