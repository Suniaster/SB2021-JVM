#include "../../include/interpretador/thread.hpp"

Thread::Thread(MethodArea* method_area){
  this->method_area = method_area;
}

void Thread::runMain(){
  MethodInfo* current_method = this->method_area->getMainMethod();

  Frame* initial_frame = new Frame(current_method, this);
  this->frame_stack.push_back(initial_frame);
  
  initial_frame->local_pc = 63;

  while(this->frame_stack.size() != 0){
    Frame* current_frame = this->frame_stack.back();
    current_frame->runInstruction();
  }
}
