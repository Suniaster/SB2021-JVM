#include "../../../include/attribute_info_classes/instruction_classes/_return.hpp"
using namespace Instructions;


_Return::_Return(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string _Return::toString(){
  return BaseInstruction::getTypePrefix(this->type) + "return";
}

int _Return::execute(Frame* frame){
  pair<uint64_t, JVMType> return_val = frame->operand_stack.pop();
  Thread* thread = frame->thread;
  frame->thread->popFrame();

  thread->getCurrentFrame()->operand_stack.push(return_val.first, return_val.second);
  
  frame->local_pc+=1;
  return frame->local_pc+1;
}