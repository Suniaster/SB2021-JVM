#ifndef __FRAME_H__
#define __FRAME_H__
class Frame;

#include "./method_area.hpp"
#include "./thread.hpp"
#include "./operand_stack.hpp"
#include "./local_variable.hpp"

using namespace std;

class Frame{
  public:
    MethodInfo* current_method;
    Thread* thread;
    
    Frame(MethodInfo*, Thread*);

    OperandStack operand_stack;
    LocalVariable local_variables;
    uint32_t local_pc;

    void runInstruction();
};

#endif
