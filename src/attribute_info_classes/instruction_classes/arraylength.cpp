#include "../../../include/attribute_info_classes/instruction_classes/arraylength.hpp"
using namespace Instructions;


ArrayLength::ArrayLength(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string ArrayLength::toString(){
  return "arraylength";
}
