#include "../../include/attribute_info_classes/inner_classes.hpp"

using namespace Attribute;

InnerClasses::InnerClasses(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
  this->class_file->setAttribute(2, this->number_of_classes);
  for(int i=0;i<this->number_of_classes;i++){
    this->pushNewInnerClassStructure();
  }
}

void InnerClasses::printInfo(int n_tabs){
  AttributeInfo::printInfo(n_tabs);
  cout << createTabs(n_tabs+1) <<"Number of InnerClassses: " << this->number_of_classes << endl;
}

void InnerClasses::pushNewInnerClassStructure(){
  InnerClassAttributes newAttribute;
  FileReader* f_reader = this->class_file->file_reader;

  f_reader->readBytes(2, newAttribute.inner_class_info_index);
  f_reader->readBytes(2, newAttribute.outer_class_info_index);
  f_reader->readBytes(2, newAttribute.inner_name_index);
  f_reader->readBytes(2, newAttribute.inner_class_access_flags);

  this->classes.push_back(newAttribute);
}