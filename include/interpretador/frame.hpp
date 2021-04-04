#ifndef __FRAME_H__
#define __FRAME_H__
class Frame;

#include "./method_area.hpp"
#include "./thread.hpp"

using namespace std;

class Frame{
  public:
    MethodInfo* current_method;
    Thread* thread;
    
    Frame(MethodInfo*, Thread*);

    vector<uint8_t> operand_stack;
    uint32_t local_pc;

    void runInstruction();
};

#endif
