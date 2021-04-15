#include "../../include/interpretador/operand_stack.hpp"

void OperandStack::push(uint64_t value, JVMType type){
  PrimitiveType* newValue = new PrimitiveType(value, type);
  operand_stack.push_back(newValue);
}

pair<uint64_t, JVMType> OperandStack::pop(){
  PrimitiveType* value = operand_stack.back();
  pair<uint64_t, JVMType> returnPair;
  returnPair.first = value->data;
  returnPair.second = value->type;

  operand_stack.pop_back();
  delete value;

  return returnPair;
}
