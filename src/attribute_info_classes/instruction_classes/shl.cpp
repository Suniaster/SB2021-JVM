#include "../../../include/attribute_info_classes/instruction_classes/shl.hpp"
using namespace Instructions;

Shl::Shl(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Shl::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "shl";
}
