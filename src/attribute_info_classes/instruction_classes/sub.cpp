#include "../../../include/attribute_info_classes/instruction_classes/sub.hpp"
using namespace Instructions;


Sub::Sub(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Sub::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "sub";
}
