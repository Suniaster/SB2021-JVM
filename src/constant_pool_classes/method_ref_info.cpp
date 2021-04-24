#include "../../include/constant_pool_classes/method_ref_info.hpp"
#include "../../include/constant_pool_classes/name_and_type_info.hpp"


CP::MethodRefInfo::MethodRefInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 10;
}

void CP::MethodRefInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->class_index);
  this->class_file->setAttribute<uint16_t>(2, this->name_and_type_index);
}

string CP::MethodRefInfo::toString(){
  string className = this->class_file->getConstantPoolEntry(this->class_index)->toString();
  string methodName =  this->class_file->getConstantPoolEntry(this->name_and_type_index)->toString();

  string methodNameParsed = methodName.substr(0, methodName.find(":"));
  return className + "." + methodNameParsed;
}

string CP::MethodRefInfo::getDescriptor(){
  CP::NameAndTypeInfo* name_info = (CP::NameAndTypeInfo*)this->class_file->getConstantPoolEntry((int)this->name_and_type_index);
  return name_info->getDescriptor();
}

void CP::MethodRefInfo::printInfo(){
  cout << "\tMethodRef: Class Index cp_info#" << this->class_index << " <" << this->class_file->getConstantPoolEntry((int)this->class_index)->toString() << ">";
  cout << "\n\tMethodRef: Name and Type Index cp_info#" << this->name_and_type_index << " <" << this->class_file->getConstantPoolEntry((int)this->name_and_type_index)->toString() << ">" << endl;

}
