#include "../../include/interpretador/frame.hpp"

Frame::Frame(MethodInfo* current_method, Thread* thread){
  this->current_method = current_method;
  this->thread = thread;
  this->local_pc = 0;


  this->local_variables.initialize(current_method->getCode()->max_locals);
}

void Frame::runInstruction(){
  Instructions::BaseInstruction* instruction = this->current_method->getInstruction(this->local_pc);
  instruction->execute(this);
}