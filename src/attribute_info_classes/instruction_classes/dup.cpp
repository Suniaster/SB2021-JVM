#include "../../../include/attribute_info_classes/instruction_classes/dup.hpp"
using namespace Instructions;


Dup::Dup(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Dup::toString(){
  return "dup";
}
