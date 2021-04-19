#include "../../../include/attribute_info_classes/instruction_classes/jsr.hpp"
using namespace Instructions;


Jsr::Jsr(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string Jsr::toString(){
  return "jsr " + this->intToString(this->branch_bytes);
}

int Jsr::execute(Frame *frame) {
  int16_t branch_offset = this->branch_bytes;
  uint32_t base_adress = frame->local_pc;

  // falta fazer um push na pilha de operandos do opcode da proxima
  // instrução, é do tipo returnAddress

  frame->local_pc = base_adress + branch_offset;
  return frame->local_pc;
}

