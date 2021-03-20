#include "../include/interface_info.hpp"

InterfaceInfo::InterfaceInfo(ClassFile *class_file) {
    this->class_file = class_file;
    this->class_file->file_reader->readBytes(2, this->interface_info);
}

void InterfaceInfo::printInfo() {
  cout << dec;
  cout << "\tIndex: \t#" << this->interface_info;
}