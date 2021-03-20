#include "../../../include/attribute_info_classes/instruction_classes/neg.hpp"
using namespace Instructions;

Neg::Neg(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Neg::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "neg";
}
