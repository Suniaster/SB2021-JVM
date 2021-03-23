#include "../../../include/attribute_info_classes/instruction_classes/jsr_w.hpp"
using namespace Instructions;


Jsr_W::Jsr_W(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Jsr_W::toString(){
  return "jsr_w " + 
    this->intToString(this->branch_bytes + this->pc) +
    " (" + this->intToSignedString(this->branch_bytes) +")"
    ;
}

