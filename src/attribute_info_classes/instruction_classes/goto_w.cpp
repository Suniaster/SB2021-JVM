#include "../../../include/attribute_info_classes/instruction_classes/goto_w.hpp"
using namespace Instructions;


Goto_W::Goto_W(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Goto_W::toString(){
  return "goto_w " + 
    this->intToString(this->branch_bytes + this->pc) +
    " (" + this->intToSignedString(this->branch_bytes) +")"
    ;
}

int Goto_W::execute(Frame *frame) {
  int32_t branch_offset = this->branch_bytes;
  uint32_t base_adress = frame->local_pc;

  frame->local_pc = base_adress + branch_offset;
  return frame->local_pc;
}

