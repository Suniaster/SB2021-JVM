#include "../../../include/attribute_info_classes/instruction_classes/pop.hpp"
using namespace Instructions;

Pop::Pop(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Pop::toString(){
  return "pop";
}

Pop2::Pop2(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Pop2::toString(){
  return "pop2";
}