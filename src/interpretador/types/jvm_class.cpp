#include "../../../include/interpretador/types/jvm_class.hpp"
#include <iostream>
#include <sstream>

JVMClass::JVMClass(string class_name):ComponentType(JVMCLASS){
  this->class_name = class_name;
}

void JVMClass::setClassFile(ClassFile* c){
  this->class_file = c;
}

PrimitiveType JVMClass::getConstant(int index){
  CpInfo* constant = this->class_file->getConstantPoolEntry(index);
  uint64_t return_data;
  JVMType return_type;


  return PrimitiveType(return_data, return_type);
} 

void JVMClass::addField(JVMField* a){
  this->fields.push_back(a);
} 

string JVMClass::toString(){
  stringstream paramString;

  paramString << "{ Class: " << this->class_file->getThisClassName() << " ";
  paramString << "fields(" << this->fields.size() << "){";
  for(uint16_t i=0;i< this->fields.size();i++){
    paramString << this->fields[i]->toString();
    if(i!=  this->fields.size()-1){
      paramString << ", ";
    }
  }
  paramString << "}}";
  return paramString.str();
}