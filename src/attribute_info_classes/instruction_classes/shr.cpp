#include "../../../include/attribute_info_classes/instruction_classes/shr.hpp"
using namespace Instructions;

Shr::Shr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Shr::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "shr";
}