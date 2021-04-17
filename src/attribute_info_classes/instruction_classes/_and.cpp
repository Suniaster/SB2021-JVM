#include "../../../include/attribute_info_classes/instruction_classes/_and.hpp"
using namespace Instructions;

And::And(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string And::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "and";
}

int And::execute(Frame* frame){
  
  uint64_t value1 = frame -> operand_stack.pop().first;
  uint64_t value2 = frame -> operand_stack.pop().first;

  switch(this->type){
    case 0: 
      int v1 = (int)value1;
      int v2 = (int)value2;
      int result = (v1 & v2);
      frame -> operand_stack.push(result, Int);
      break;
    case 1: 
      int64_t v1 = (int64_t)value1;
      int64_t v2 = (int64_t)value2;
      int64_t result = (v1 & v2);
      frame -> operand_stack.push(result, Long);
      break;
  }

  return frame -> local_pc++;
}