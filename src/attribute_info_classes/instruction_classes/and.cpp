#include "../../../include/attribute_info_classes/instruction_classes/and.hpp"
using namespace Instructions;

And::And(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string And::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "and";
}
