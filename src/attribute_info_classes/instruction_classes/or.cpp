#include "../../../include/attribute_info_classes/instruction_classes/or.hpp"
using namespace Instructions;


Or::Or(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Or::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "or";
}
