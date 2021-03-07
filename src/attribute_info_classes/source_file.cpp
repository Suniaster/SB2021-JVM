#include "../../include/attribute_info_classes/source_file.hpp"

Attribute::SourceFile::SourceFile(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  this->class_file->setAttribute(2, this->sourcefile_index);
}

void Attribute::SourceFile::printInfo(){
  AttributeInfo::printInfo();
  cout << "\tSource file name index: #" << this->sourcefile_index;
  cout << " <" << this->getFileName() << ">" << endl;
}

string Attribute::SourceFile::getFileName(){
  return this->class_file->getConstantPoolUtf8String(this->sourcefile_index);
}