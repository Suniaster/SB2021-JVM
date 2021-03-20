#include "../../../include/attribute_info_classes/instruction_classes/if__cmp.hpp"
using namespace Instructions;


If_cmp::If_cmp(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string If_cmp::toString(){
  int jump_total = 0;

  jump_total = this->pc + this->branch_bytes;

  return this->types[this->type] + 
    " " + 
    this->intToString(jump_total) +
    " (+" +
    this->intToString(this->branch_bytes) +
    ")"
    ;
}

