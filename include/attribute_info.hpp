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
    uint16_t attribute_name_index;
    uint32_t attribute_length;

  public:
    ClassFile *class_file;
    AttributeInfo(Attribute::AttrInitialValue initial);

    string getAttributeName();

    virtual void printInfo();
    virtual void setInfo() = 0;

    static AttributeInfo* getInstance(
      ClassFile* class_file
    );
    static void loadAttributes(vector<AttributeInfo*> &attributes, uint16_t size, ClassFile* class_file);
    static void printAttributes(vector<AttributeInfo*> attributes);
};


#endif
