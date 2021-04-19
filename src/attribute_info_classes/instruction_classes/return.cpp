#include "../../../include/attribute_info_classes/instruction_classes/return.hpp"
using namespace Instructions;


Return::Return(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Return::toString(){
  return "return";
}

int Return::execute(Frame* frame){
  frame->thread->popFrame();
  return 0;
}