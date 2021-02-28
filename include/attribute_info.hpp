#ifndef __ATTRIBUTE_INFO_H__
#define __ATTRIBUTE_INFO_H__
class AttributeInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"

using namespace std;


namespace Attribute{
  typedef struct{
    ClassFile *class_file;
    uint16_t attribute_name_index; 
    uint32_t attribute_length;
  }AttrInitialValue;
}

class AttributeInfo{
  protected: 
    ClassFile *class_file;
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t sourcefile_index;

  public:
    AttributeInfo(Attribute::AttrInitialValue initial);

    string getAttributeName();

    virtual void printInfo();
    virtual void setInfo() = 0;

    static AttributeInfo* getInstance(
      ClassFile* class_file, 
      uint16_t attribute_name_index,
      uint32_t attribute_length
    );
};


#endif
