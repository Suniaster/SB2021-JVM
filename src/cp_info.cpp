#include "../include/cp_info.hpp"
#include "../include/constant_pool_classes/method_ref_info.hpp"

CpInfo::CpInfo(ClassFile* class_file){
  this->class_file = class_file;
}

CpInfo* CpInfo::getInstance(uint8_t tag, ClassFile* class_file){
  CpInfo* correct_instance;
  switch (tag){
  case 10:
    correct_instance = new CP::MethodRefInfo(class_file);
    break;
  default:
    correct_instance = new CP::MethodRefInfo(class_file);
    break;
  }
  return correct_instance;
}