#include "../../include/interpretador/operand_stack.hpp"

void OperandStack::push(uint64_t value){
  operand_stack.push_back(value);
}

uint64_t OperandStack::pop(){
  uint64_t value = operand_stack.back();
  operand_stack.pop_back();
  return value;
}
