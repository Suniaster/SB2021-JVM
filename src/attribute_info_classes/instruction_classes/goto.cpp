#include "../../../include/attribute_info_classes/instruction_classes/goto.hpp"
using namespace Instructions;


Goto::Goto(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Goto::toString(){
  int branch_pc = 0;
  string signal = "+";
  int16_t jump_total = this->branch_bytes;

  branch_pc = (int16_t)this->pc + jump_total;

  if(jump_total < 0){ 
    signal = "-";
    jump_total *= -1;
  }

  
  return "goto " + 
    this->intToString(branch_pc) +
    " (" + signal +
    this->intToString(jump_total) +
    ")"
    ;
}

