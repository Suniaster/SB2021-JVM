#include "../../../include/attribute_info_classes/instruction_classes/athrow.hpp"
#include "../../../include/interpretador/types/exception_type.hpp"

using namespace Instructions;


Athrow::Athrow(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Athrow::toString(){
  return "athrow";
}

int Athrow::execute(Frame* frame) {
  pair<uint64_t, JVMType> val = frame->operand_stack.pop();
  ExceptionType* exception = (ExceptionType*) Heap::getInstance()->getReference(val.first);
  
  throw std::runtime_error(exception->toString());

  frame->local_pc += 1;
  return frame->local_pc;
}
