#include "../../../include/attribute_info_classes/instruction_classes/jsr.hpp"
using namespace Instructions;


Jsr::Jsr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Jsr::toString(){
  return "jsr " + this->intToString(this->branch_bytes);
}

