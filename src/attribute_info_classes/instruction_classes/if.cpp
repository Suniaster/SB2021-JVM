#include "../../../include/attribute_info_classes/instruction_classes/if.hpp"
using namespace Instructions;


If::If(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string If::toString(){
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

