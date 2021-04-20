#include "../../../include/attribute_info_classes/instruction_classes/pop.hpp"

using namespace Instructions;

Pop::Pop(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Pop::toString(){
  return "pop";
}

int Pop::execute(Frame *frame) {
  frame->operand_stack.pop();
  frame->local_pc += 1;

  return frame->local_pc;
}

Pop2::Pop2(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Pop2::toString(){
  return "pop2";
}

int Pop2::execute(Frame *frame) {
  JVMType type = frame->operand_stack.pop().second;

  if (type != Long && type != Double)
    frame->operand_stack.pop();

  frame->local_pc += 1;

  return frame->local_pc;
}