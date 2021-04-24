#include "../../../include/attribute_info_classes/instruction_classes/swap.hpp"
using namespace Instructions;


Swap::Swap(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string Swap::toString(){
  return "swap";
}

int Swap::execute(Frame *frame) {
  pair<uint64_t, JVMType> value1 = frame->operand_stack.pop();
  pair<uint64_t, JVMType> value2 = frame->operand_stack.pop();

  frame->operand_stack.push(value1.first, value1.second);
  frame->operand_stack.push(value2.first, value2.second);

  frame->local_pc += 1;
  return frame->local_pc;
}