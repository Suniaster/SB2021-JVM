#include "../../include/attribute_info_classes/exceptions.hpp"

Attribute::Exceptions::Exceptions(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  FileReader* f_reader = this->class_file->file_reader;
  f_reader->readBytes(2, this->number_of_exceptions);
  for(int i=0;i<this->number_of_exceptions;i++){
    uint16_t index_table;
    f_reader->readBytes(2, index_table);
    this->exception_index_table.push_back(index_table);
  }
}

void Attribute::Exceptions::printInfo(){
  AttributeInfo::printInfo();
  cout << "\tNumber of exceptions name index: #" << this->number_of_exceptions << endl;
  for(int i=0;i<this->number_of_exceptions;i++){
    cout << "\t\tindex: #" << this->exception_index_table[i] << endl;
  }
}