#ifndef __METHOD_INFO_H__
#define __METHOD_INFO_H__
class MethodInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"
#include "./attribute_info.hpp"

// Declaracoes pra evitar inclusao ciclica
namespace Attribute{ class CodeAttribute; };
namespace Instructions{ class BaseInstruction; };

class MethodInfo{
  private:
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    vector<AttributeInfo*> attributes;

  public:
    ClassFile *class_file;
    MethodInfo(ClassFile *class_file);
    ~MethodInfo();

    Attribute::CodeAttribute* getCode();
    Instructions::BaseInstruction* getInstruction(int pc);

    string getName();
    void printInfo();
};

#endif