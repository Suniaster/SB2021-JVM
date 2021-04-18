#include "../../include/constant_pool_classes/name_and_type_info.hpp"



CP::NameAndTypeInfo::NameAndTypeInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 12;
}

void CP::NameAndTypeInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->name_index);
  this->class_file->setAttribute<uint16_t>(2, this->descriptor_index);
}

string CP::NameAndTypeInfo::toString(){
     return this->class_file->getConstantPoolEntry(this->name_index)->toString() + ":" +this->class_file->getConstantPoolEntry(this->descriptor_index)->toString();
}

void CP::NameAndTypeInfo::printInfo(){
    cout << "\tName and Type: Name Index cp_info#" << this->name_index << " <" <<this->class_file->getConstantPoolEntry((int)this->name_index)->toString() << ">" << endl;
    cout << "\tName and Type: Descriptor Index cp_info#" << this->descriptor_index << " <"<<  this->class_file->getConstantPoolEntry((int)this->descriptor_index)->toString() << ">" << endl;

}

// string CP::NameAndTypeInfo::returnResolvedName(){
//     return this->class_file->getConstantPoolEntry((int)this->name_index)->toString();
// }

// string CP::NameAndTypeInfo::returnResolvedType(){
//     return  this->class_file->getConstantPoolEntry((int)this->descriptor_index)->toString();
// }
