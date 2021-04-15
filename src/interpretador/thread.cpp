#include "../../include/interpretador/thread.hpp"

Thread::Thread(MethodArea* method_area, Heap* heap_ref){
  this->method_area = method_area;
  this->heap_ref = heap_ref;
}

void Thread::runMain(){
  MethodInfo* current_method = this->method_area->getMainMethod();

  Frame* initial_frame = new Frame(current_method, this);
  this->frame_stack.push_back(initial_frame);
  
  initial_frame->local_pc = 43;

  while(this->frame_stack.size() != 0){
    Frame* current_frame = this->frame_stack.back();
    current_frame->runInstruction();
  }
}
