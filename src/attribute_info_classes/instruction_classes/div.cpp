#include "../../../include/attribute_info_classes/instruction_classes/div.hpp"
using namespace Instructions;

Div::Div(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Div::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "div";
}
