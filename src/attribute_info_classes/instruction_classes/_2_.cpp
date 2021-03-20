#include "../../../include/attribute_info_classes/instruction_classes/_2_.hpp"
using namespace Instructions;


TypeConversion::TypeConversion(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string TypeConversion::toString(){
  return this->types[this->type];
}

