#include "../../../include/attribute_info_classes/instruction_classes/inc.hpp"
using namespace Instructions;


Inc::Inc(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Inc::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "inc";
}

