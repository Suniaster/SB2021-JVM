#include "../../include/interpretador/thread.hpp"

Thread::Thread(MethodArea* method_area){
  this->method_area = method_area;
}

void Thread::runMain(){
  MethodInfo* current_method = this->method_area->getMainMethod();

  Frame* inital_frame = new Frame(current_method, this);
  this->frame_stack.push_back(inital_frame);

  while(this->frame_stack.size() != 0){
    Frame* current_frame = this->frame_stack.back();
    current_frame->runInstruction();
  }
}
