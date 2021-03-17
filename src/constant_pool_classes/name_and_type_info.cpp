#include "../../include/constant_pool_classes/name_and_type_info.hpp"



CP::NameAndTypeInfo::NameAndTypeInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 12;
}

void CP::NameAndTypeInfo::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->name_index);
  this->class_file->setAttribute<uint16_t>(2, this->descriptor_index);
}

void CP::NameAndTypeInfo::printInfo(){
    cout << "\tName and Type: Name Index " << this->name_index << endl;
    cout << "\n";
    CpInfo* name_utf_info = this->class_file->getConstantPoolEntry((int)this->name_index);
    name_utf_info->printInfo();

    cout << "\n\tName and Type: Descriptor Index " << this->descriptor_index << endl;
    cout << "\n";
    CpInfo* descriptor_utf_info = this->class_file->getConstantPoolEntry((int)this->descriptor_index);
    descriptor_utf_info->printInfo();
}
