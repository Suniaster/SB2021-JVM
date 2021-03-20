#include "../../include/constant_pool_classes/class_info.hpp"



CP::ClassInfo::ClassInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 7;
}

void CP::ClassInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->name_index);
}

string CP::ClassInfo::toString(){
  return "<" + this->class_file->getConstantPoolEntry(this->name_index)->toString() + ">";
}

void CP::ClassInfo::printInfo(){
  cout << "\tClass: Name Index " << this->name_index << " <"<< this->class_file->getConstantPoolEntry((int)this->name_index)->toString()<< ">" << endl;
}
