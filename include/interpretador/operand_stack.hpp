#ifndef __OPERAND_STACK_H__
#define __OPERAND_STACK_H__

#include <vector>
#include <cstdint>
#include "./types/primitive_type.hpp"
#include <utility>

using namespace std;

class OperandStack {
  private:
    vector<PrimitiveType*> operand_stack;
  public:

    pair<uint64_t, JVMType> pop();
    void push(uint64_t value, JVMType type);
    void print();
};

#endif