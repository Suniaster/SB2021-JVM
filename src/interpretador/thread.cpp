#include "../../include/interpretador/thread.hpp"

Thread::Thread(MethodArea* method_area){
  this->method_area = method_area;
  this->heap_ref = Heap::getInstance();
}

void Thread::runMain(){
  MethodInfo* current_method = this->method_area->getMainMethod();

  Frame* initial_frame = new Frame(current_method, this);
  this->frame_stack.push_back(initial_frame);
  
  this->start();
}

void Thread::start(){
  while(this->frame_stack.size() != 0){
    Frame* current_frame = this->frame_stack.back();
    cout << "Executando inst: " << current_frame->local_pc << endl;
    current_frame->runInstruction();
  }
}

void Thread::invokeStaticMethod(string class_name, string methodName, Frame* previous_frame){
  cout << "invokeStaticMethod: Invocando metodo " << methodName << endl;
  MethodInfo* method = this->method_area->getMethodByName(class_name, methodName);
  int n_args = method->getArgsCount();
  Frame* new_frame = new Frame(method, this);

  for(int i=0;i<n_args;i+=1){
    // TODO: Conferir tipagem na passagem de argumento
    pair<uint64_t, JVMType> arg = previous_frame->operand_stack.pop();

    new_frame->local_variables.insert(i+1, arg.first, arg.second);

    if(arg.second == Long || arg.second == Double)i++;
  }

  this->frame_stack.push_back(new_frame);
}

void Thread::popFrame(){
  Frame* current_frame = this->frame_stack.back();
  this->frame_stack.pop_back();
  delete current_frame;
}

Frame* Thread::getCurrentFrame(){
  return this->frame_stack.back();
}