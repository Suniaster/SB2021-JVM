#ifndef __FIELD_INFO_H__
#define __FIELD_INFO_H__
class FieldInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"
#include "./attribute_info.hpp"

using namespace std;

class FieldInfo{
private:
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    vector<AttributeInfo*> attributes;
    ClassFile *class_file;

public:
    FieldInfo(ClassFile *class_file);

    void printInfo();
};


#endif
