#ifndef __THREAD_H__
#define __THREAD_H__
class Thread;

#include "./method_area.hpp"
#include "./frame.hpp"
#include "./heap.hpp"

using namespace std;

class Thread{
  private:
    MethodArea* method_area;
    uint32_t pc_register;
    
    MethodInfo* current_method;
    vector<Frame*> frame_stack; 

  public:
    Heap* heap_ref;
    Thread(MethodArea*, Heap*);

    void runMain();
};

#endif
