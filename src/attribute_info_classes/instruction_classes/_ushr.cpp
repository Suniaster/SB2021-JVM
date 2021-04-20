#include "../../../include/attribute_info_classes/instruction_classes/_ushr.hpp"
using namespace Instructions;

Ushr::Ushr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Ushr::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "ushr";
}

int Ushr::execute(Frame* frame){
  
  uint64_t value1 = frame -> operand_stack.pop().first;
  uint64_t value2 = frame -> operand_stack.pop().first;

  switch(this->type){
    case 0: 
      uint32_t v1 = (uint32_t)value1;
      int32_t v2 = (int32_t)value2;
      int result = v1 >> (v2 & 0x1F);
      frame -> operand_stack.push(result, Int);
      break;
    case 1: 
      uint64_t v1 = (uint64_t)value1;
      int32_t v2 = (int32_t)value2;
      int64_t result = v1 >> (v2 & 0x3F);
      frame -> operand_stack.push(result, Long);
      break;
  }

  return frame -> local_pc++;
}