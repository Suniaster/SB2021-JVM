#ifndef __METHOD_INFO_H__
#define __METHOD_INFO_H__
class MethodInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"
#include "./attribute_info.hpp"

class MethodInfo{
  private:
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    ClassFile* class_file;
    vector<AttributeInfo*> attributes;

  public:
    MethodInfo(ClassFile *class_file);
    void printInfo();
};

#endif