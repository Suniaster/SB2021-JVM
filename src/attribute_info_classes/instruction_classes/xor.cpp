#include "../../../include/attribute_info_classes/instruction_classes/xor.hpp"
using namespace Instructions;


Xor::Xor(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Xor::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "xor";
}

