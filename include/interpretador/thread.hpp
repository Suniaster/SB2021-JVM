#ifndef __THREAD_H__
#define __THREAD_H__
class Thread;

#include "./method_area.hpp"
#include "./frame.hpp"

using namespace std;

class Thread{
  private:
    MethodArea* method_area;
    uint32_t pc_register;
    
    MethodInfo* current_method;
    vector<Frame*> frame_stack; 
  public:
    Thread(MethodArea*);

    void runMain();
};

#endif
