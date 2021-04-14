#ifndef __OPERAND_STACK_H__
#define __OPERAND_STACK_H__

#include <vector>
#include "../JVMTypes/jvm_type.hpp"

class OperandStack {
  private:
    vector<JVMType *> operand_stack;
  public:
    template<typename T>
    T pop();

    template<typename T>
    void push(T);
};

template <typename T>
T OperandStack::pop() {
  JVMType_t<T> * value = (JVMType_t<T> *) operand_stack.back();

  operand_stack.pop_back();

  delete value;
  return value->data;
}

template <typename T>
void OperandStack::push(T data) {
  JVMType_t<T> * value = new JVMType_t<T>();
  value->data = data;
  operand_stack.push_back(value);
}

#endif