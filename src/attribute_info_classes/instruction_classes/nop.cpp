#include "../../../include/attribute_info_classes/instruction_classes/nop.hpp"
using namespace Instructions;


Nop::Nop(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

int Nop::BaseInstruction::execute(Frame *frame){
    return frame->local_pc++;
}

string Nop::toString(){
  return "nop";
}
