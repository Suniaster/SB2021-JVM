#ifndef __THREAD_H__
#define __THREAD_H__
class Thread;

#include "./method_area.hpp"
#include "./frame.hpp"
#include "./heap.hpp"

using namespace std;

#define VERBOSE_INSTRUCTION_PC 1
#define VERBOSE_INSTRUCTION_INVOKE 0
class Thread{
  private:
    uint32_t pc_register;
    
    MethodInfo* current_method;
    vector<Frame*> frame_stack; 

    void initializeFrameVariableVector(Frame*, int n_args, int initial_pos);

  public:
    MethodArea* method_area;
    Heap* heap_ref;
    Thread(MethodArea*);

    void invokeStaticMethod(string class_name, string methodName, string args_descriptor);
    void invokeInstanceMethod(string class_name, string methodName, string args_descriptor);
    void popFrame();
    Frame* getCurrentFrame();
    
    void runMain();
    void start();
};

#endif
