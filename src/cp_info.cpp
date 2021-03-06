#include "../include/cp_info.hpp"
#include "../include/constant_pool_classes/method_ref_info.hpp"
#include "../include/constant_pool_classes/class_info.hpp"
#include "../include/constant_pool_classes/utf8_info.hpp"
#include "../include/constant_pool_classes/string_info.hpp"
#include "../include/constant_pool_classes/name_and_type_info.hpp"
#include "../include/constant_pool_classes/field_ref_info.hpp"
#include "../include/constant_pool_classes/interface_method_ref_info.hpp"

CpInfo::CpInfo(ClassFile* class_file){
  this->class_file = class_file;
}

CpInfo* CpInfo::getInstance(uint8_t tag, ClassFile* class_file){
  CpInfo* correct_instance;
  switch (tag){
  case 0x1:
    correct_instance = new CP::Utf8Info(class_file);
    break;
  case 0x7:
    correct_instance = new CP::ClassInfo(class_file);
    break;
  case 0x8:
    correct_instance = new CP::StringInfo(class_file);
    break;
  case 0x9:
    correct_instance = new CP::FieldRefInfo(class_file);
    break;
  case 0x10:
    correct_instance = new CP::MethodRefInfo(class_file);
    break;
  case 0x11:
    correct_instance = new CP::InterfaceMethodRefInfo(class_file);
    break;
  case 0x12:
    correct_instance = new CP::NameAndTypeInfo(class_file);
    break;

  default:
    correct_instance = new CP::MethodRefInfo(class_file);
    break;
  }
  return correct_instance;
}
