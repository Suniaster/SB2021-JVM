#include "../include/field_info.hpp"

FieldInfo::FieldInfo(ClassFile *class_file) {
  this->class_file = class_file;
  this->class_file->file_reader->readBytes(2, this->access_flags);
  this->class_file->file_reader->readBytes(2, this->name_index);
  this->class_file->file_reader->readBytes(2, this->descriptor_index);
  this->class_file->file_reader->readBytes(2, this->attributes_count);
  AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);
}

void FieldInfo::printInfo() {
  cout << dec;
  cout << "\tName: \t#" << this->name_index << endl;
  cout << "\tDescriptor: \t#" << this->descriptor_index << endl;
  cout << "\tAccess flags: \t" << hex << this->access_flags << endl;
  cout << "\tAttributes count: \t" << hex << this->attributes_count << endl;

  if (this->attributes_count) {
    cout << "\t Attributes:";
    AttributeInfo::printAttributes(this->attributes, 1);
    cout << endl;
  }
}