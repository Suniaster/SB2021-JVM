#ifndef __ATTRIBUTE_INFO_H__
#define __ATTRIBUTE_INFO_H__
class AttributeInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"

using namespace std;


class AttributeInfo{
  protected: 
    ClassFile *class_file;
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t sourcefile_index;

  public:
    AttributeInfo(ClassFile *class_file, uint16_t attribute_name_index, uint32_t attribute_length);

    virtual void setInfo() = 0;
    virtual void printInfo() = 0;

    static AttributeInfo* getInstance(
      ClassFile* class_file, 
      uint16_t attribute_name_index,
      uint32_t attribute_length
    );
};


#endif
