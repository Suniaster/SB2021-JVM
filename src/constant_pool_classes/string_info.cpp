#include "../../include/constant_pool_classes/string_info.hpp"



CP::StringInfo::StringInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 8;
}

void CP::StringInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->string_index);
}

void CP::StringInfo::printInfo(){
  cout << "\tString: String Index cp_info# " <<   this->string_index << " <" <<this->class_file->getConstantPoolEntry((int)this->string_index)->toString() << ">"  << endl;
}

string CP::StringInfo::toString(){
  CpInfo* newIndex = this->class_file->getConstantPoolEntry(this->string_index);
  return newIndex->toString();
}
