#include "../include/method_info.hpp"

MethodInfo::MethodInfo(ClassFile *class_file) {
    this->class_file = class_file;
    this->class_file->file_reader->readBytes(2, this->access_flags);
    this->class_file->file_reader->readBytes(2, this->name_index);
    this->class_file->file_reader->readBytes(2, this->descriptor_index);
    this->class_file->file_reader->readBytes(2, this->attributes_count);
    AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);
}

void MethodInfo::printInfo() {
  cout << dec;
  cout << "\tName: \t\t#" << this->name_index << " " << this->class_file->getConstantPoolEntry(this->name_index)->toString() << endl;
  cout << "\tDescriptor: \t#" << this->descriptor_index << " " << this->class_file->getConstantPoolEntry(this->descriptor_index)->toString() << endl;
  cout << "\tAccess flags: \t" << hex << this->access_flags << endl;
  AttributeInfo::printAttributes(this->attributes, 2);
}
