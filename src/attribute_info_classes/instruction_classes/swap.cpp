#include "../../../include/attribute_info_classes/instruction_classes/swap.hpp"
using namespace Instructions;


Swap::Swap(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string Swap::toString(){
  return "swap";
}
