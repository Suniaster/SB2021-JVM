#include "../../../include/attribute_info_classes/instruction_classes/mul.hpp"
using namespace Instructions;


Mul::Mul(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Mul::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "mul";
}
