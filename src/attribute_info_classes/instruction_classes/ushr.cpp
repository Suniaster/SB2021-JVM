#include "../../../include/attribute_info_classes/instruction_classes/ushr.hpp"
using namespace Instructions;

Ushr::Ushr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Ushr::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "ushr";
}
