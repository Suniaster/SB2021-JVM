#include "../../../include/attribute_info_classes/instruction_classes/_shr.hpp"
using namespace Instructions;

Shr::Shr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Shr::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "shr";
}

int Shr::execute(Frame* frame){
  
  uint64_t value1 = frame -> operand_stack.pop().first;
  uint64_t value2 = frame -> operand_stack.pop().first;

  switch(this->type){
    case 0: 
      int v1 = (int)value1;
      int v2 = (int)value2;
      int result = v1 >> (v2 & 0x1F);
      frame -> operand_stack.push(result, Int);
      break;
    case 1: 
      int64_t v1 = (int64_t)value1;
      int64_t v2 = (int64_t)value2;
      int64_t result = v1 >> (v2 & 0x3F);
      frame -> operand_stack.push(result, Long);
      break;
  }

  return frame -> local_pc++;
}