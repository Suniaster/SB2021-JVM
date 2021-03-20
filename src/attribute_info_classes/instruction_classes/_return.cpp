#include "../../../include/attribute_info_classes/instruction_classes/_return.hpp"
using namespace Instructions;


_Return::_Return(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string _Return::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "return";
}
