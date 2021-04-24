#include "../../include/interpretador/thread.hpp"
#include <list>
#include <algorithm>

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
    if(VERBOSE_INSTRUCTION_PC){
      cout << "(" << current_frame->current_method->getName() << ")";
      cout << "Executando inst: " << current_frame->local_pc << endl;
    }
    current_frame->runInstruction();
  }
}

void Thread::initializeFrameVariableVector(Frame* f, int n_args, int initial_pos){
  Frame* previous_frame = NULL;
  
  if(this->frame_stack.size() > 0)
    previous_frame = this->frame_stack.back();
  else if(n_args > 0) throw std::runtime_error("InvokeMethodError: invocando metodo com argumentos inexistentes no programa");

  vector<pair<uint64_t, JVMType>> args;
  for(int i=0;i<n_args;i+=1){
    pair<uint64_t, JVMType> arg = previous_frame->operand_stack.pop();
    args.push_back(arg);
  }

  reverse(args.begin(), args.end());

  int desloc = 0;
  int insertPosition = initial_pos;
  for(int i=0 ; i<n_args; i++ ){
    // TODO: Conferir tipagem na passagem de argumento
    pair<uint64_t, JVMType> arg = args[i];
    insertPosition = i + initial_pos + desloc;
    f->local_variables.insert(insertPosition + desloc, arg.first, arg.second);
    if(arg.second == Long || arg.second == Double)desloc++;
  }
}

void Thread::invokeStaticMethod(string class_name, string methodName, string args_descriptor){
  MethodInfo* method = this->method_area->getMethodByName(class_name, methodName, args_descriptor);
  int n_args = method->getArgsCount();
  Frame* new_frame = new Frame(method, this);

  if(VERBOSE_INSTRUCTION_INVOKE){
    cout << "invokeStaticMethod: Invocando metodo:" << methodName << " n_agrs: " << endl;
  }
  this->initializeFrameVariableVector(new_frame, n_args, 0);
  
  this->frame_stack.push_back(new_frame);
}

void Thread::invokeInstanceMethod(string class_name, string methodName, string args_descriptor){

  MethodInfo* method = this->method_area->getMethodByName(class_name, methodName, args_descriptor);
  int n_args = method->getArgsCount();
  Frame* new_frame = new Frame(method, this);
  if(VERBOSE_INSTRUCTION_INVOKE){
    cout << "invokeInstanceMethod: Invocando metodo:" << methodName << " classname: " << class_name;
    cout << " argscount: " << n_args << endl;
  }
  this->initializeFrameVariableVector(new_frame, n_args+1, 0);

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