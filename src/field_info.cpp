#include "../include/field_info.hpp"

FieldInfo::FieldInfo(ClassFile *class_file) {
  this->class_file = class_file;
  this->class_file->file_reader->readBytes(2, this->access_flags);
  this->class_file->file_reader->readBytes(2, this->name_index);
  this->class_file->file_reader->readBytes(2, this->descriptor_index);
  this->class_file->file_reader->readBytes(2, this->attributes_count);
  AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);
}

FieldInfo::~FieldInfo() {
  this->class_file->deleteVector(this->attributes);
}

void FieldInfo::printInfo() {
  cout << "\tName:              cpinfo #" << this->name_index << " <";
  cout << this->class_file->getConstantPoolEntry(this->name_index)->toString() << ">" << endl;
  cout << "\tDescriptor:        cpinfo #" << this->descriptor_index << " <";
  cout << this->class_file->getConstantPoolEntry(this->descriptor_index)->toString() << ">" << endl;
  cout << "\tAccess flags:      0x" <<  hex << this->access_flags << " " << this->class_file->beautifiedAccessFlags(this->access_flags, true, false) << endl;

  AttributeInfo::printAttributes(this->attributes, 2);
}

string FieldInfo::getName() {
  return this->class_file->getConstantPoolEntry(this->name_index)->toString();
}

string FieldInfo::getDescriptor() {
  return this->class_file->getConstantPoolEntry(this->descriptor_index)->toString();
}

bool FieldInfo::isStatic() {
  if(this->class_file->beautifiedAccessFlags(this->access_flags, true, false)
    .find("static") != string::npos
  )
    return true;
  else return false;
}