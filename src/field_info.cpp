#include "../include/field_info.hpp"

FieldInfo::FieldInfo(ClassFile *class_file) {
    this->class_file = class_file;
    this->class_file->file_reader->readBytes(2, this->access_flags);
    this->class_file->file_reader->readBytes(2, this->name_index);
    this->class_file->file_reader->readBytes(2, this->descriptor_index);
    this->class_file->file_reader->readBytes(2, this->attributes_count);
}