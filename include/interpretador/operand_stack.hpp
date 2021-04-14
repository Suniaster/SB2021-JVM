#ifndef __OPERAND_STACK_H__
#define __OPERAND_STACK_H__

#include <vector>
#include <cstdint>

using namespace std;

class OperandStack {
  private:
    vector<uint64_t> operand_stack;
  public:

    uint64_t pop();
    void push(uint64_t);
};

#endif