#include "../../../include/attribute_info_classes/instruction_classes/mul.hpp"
using namespace Instructions;


Mul::Mul(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string Mul::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "mul";
}

int Mul::execute(Frame* frame){
  
  uint64_t value1 = frame -> operand_stack.pop().first;
  uint64_t value2 = frame -> operand_stack.pop().first;

  switch(this->type){
    case 0: 
      int v1 = (int)value1;
      int v2 = (int)value2;
      int result = v1 * v2;
      frame -> operand_stack.push(result, Int);
      break;
    case 1: 
      int64_t v1 = (int64_t)value1;
      int64_t v2 = (int64_t)value2;
      int64_t result = v1 * v2;
      frame -> operand_stack.push(result, Long);
      break;
    case 2:
      float v1 = *(float*)&value1;
      float v2 = *(float*)&value2;
      float result = v1 * v2;
      frame -> operand_stack.push(result, Float);
      break;
    case 3:
      double v1 = *(double*)&value1;
      double v2 = *(double*)&value2;
      double result = v1 * v2;
      frame -> operand_stack.push(result, Double);
      break;
  }

  return frame -> local_pc++;
}