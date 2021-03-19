#include "../../../include/attribute_info_classes/instruction_classes/add.hpp"
using namespace Instructions;


Add::Add(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->ADD_BASE_OPCODE;  
}

string Add::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "add";
}
