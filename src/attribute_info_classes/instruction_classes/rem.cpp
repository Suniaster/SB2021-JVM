#include "../../../include/attribute_info_classes/instruction_classes/rem.hpp"
using namespace Instructions;

Rem::Rem(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Rem::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "rem";
}
