#include "../../../include/attribute_info_classes/instruction_classes/arraylength.hpp"
#include "../../../include/interpretador/types/array_type.hpp"

using namespace Instructions;


ArrayLength::ArrayLength(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string ArrayLength::toString(){
  return "arraylength";
}

int ArrayLength::execute(Frame* frame){
  int array_ref = frame->operand_stack.pop().first;
  ArrayType* array = (ArrayType*)Heap::getInstance()->getReference(array_ref);
  frame->operand_stack.push(array->getLength(), Int);
  return frame->local_pc+=1;
}