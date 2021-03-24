#include "../include/method_info.hpp"

MethodInfo::MethodInfo(ClassFile *class_file) {
    this->class_file = class_file;
    this->class_file->file_reader->readBytes(2, this->access_flags);
    this->class_file->file_reader->readBytes(2, this->name_index);
    this->class_file->file_reader->readBytes(2, this->descriptor_index);
    this->class_file->file_reader->readBytes(2, this->attributes_count);
    AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);
}

MethodInfo::~MethodInfo() {
  this->class_file->deleteVector(this->attributes);
}

void MethodInfo::printInfo() {
  cout << dec;
  cout << "\tName:              cpinfo #" << this->name_index << " <" << this->class_file->getConstantPoolEntry(this->name_index)->toString() << ">" << endl;
  cout << "\tDescriptor:        cpinfo #" << this->descriptor_index << " <" << this->class_file->getConstantPoolEntry(this->descriptor_index)->toString() << ">" << endl;
  cout << "\tAccess flags:      0x" << hex << this->access_flags << " " << this->class_file->beautifiedAccessFlags(this->access_flags, false, true) << endl;
  AttributeInfo::printAttributes(this->attributes, 2);
}
