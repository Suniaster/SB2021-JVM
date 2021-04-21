#include "../../include/interpretador/operand_stack.hpp"
#include <iostream>

void OperandStack::print(){
  std::cout << "PILHA" << endl;
  for(size_t i=0; i < this->operand_stack.size();i++){
    this->operand_stack[i]->print();
  }
  std::cout << "FIMPILHA" << endl;
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

void OperandStack::push(uint64_t value, JVMType type)
{
  PrimitiveType *newValue = new PrimitiveType(value, type);
  operand_stack.push_back(newValue);
}

void OperandStack::insert(int index, uint64_t value, JVMType type)
{
  PrimitiveType *newValue = new PrimitiveType(value, type);
  operand_stack.insert(operand_stack.end() - index, newValue);
}

pair<uint64_t, JVMType> OperandStack::readPosition(int position)
{
  int end = operand_stack.size()-1;
  pair<uint64_t, JVMType> positionValue(operand_stack[end-position]->data, operand_stack[end-position]->type);
  return positionValue;
}