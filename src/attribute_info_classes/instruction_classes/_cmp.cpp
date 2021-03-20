#include "../../../include/attribute_info_classes/instruction_classes/_cmp.hpp"
using namespace Instructions;


Compare::Compare(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Compare::toString(){
  return this->types[this->type];
}

