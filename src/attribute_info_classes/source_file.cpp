#include "../../include/attribute_info_classes/source_file.hpp"

Attribute::SourceFile::SourceFile(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  this->class_file->setAttribute(2, this->sourcefile_index);

  string cp_file_name = this->class_file->getConstantPoolUtf8String(this->sourcefile_index);
  string source_file_name = this->class_file->file_reader->getFileName();

  if(source_file_name.find(this->removeSubString(cp_file_name, ".java") + ".class") == std::string::npos){
      throw std::invalid_argument("Invalid source  name");
  }
}

void Attribute::SourceFile::printInfo(int n_tabs){
  AttributeInfo::printInfo(n_tabs);
  cout << createTabs(n_tabs+1) << "Source file name index: #" << this->sourcefile_index;
  cout << " <" << this->getFileName() << ">" << endl;
}

string Attribute::SourceFile::getFileName(){
  return this->class_file->getConstantPoolUtf8String(this->sourcefile_index);
}

string Attribute::SourceFile::removeSubString(string initial, string sub_string){

  std::string::size_type sub_string_size = initial.find(sub_string);

  if (sub_string_size != std::string::npos){
    return initial.erase(sub_string_size, sub_string.length());
  }else {
    return initial;
  }

}
