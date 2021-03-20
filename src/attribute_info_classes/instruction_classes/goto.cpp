#include "../../../include/attribute_info_classes/instruction_classes/goto.hpp"
using namespace Instructions;


Goto::Goto(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Goto::toString(){
  int jump_total = 0;

  jump_total = (int)this->pc + (int)this->branch_bytes;

  return "goto " + 
    this->intToString(jump_total) +
    " (+" +
    this->intToString(this->branch_bytes) +
    ")"
    ;
}

