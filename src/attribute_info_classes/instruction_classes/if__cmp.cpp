#include "../../../include/attribute_info_classes/instruction_classes/if__cmp.hpp"
using namespace Instructions;


If_icmp::If_icmp(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
  this->code_attr->class_file->file_reader->readBytes(2, this->branch_bytes);
}

string If_icmp::toString(){
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

int If_icmp::execute(Frame *frame) {
  int64_t value2 = frame->operand_stack.pop().first;
  int64_t value1 = frame->operand_stack.pop().first;

  switch(this->type) {
    case 0:
      if((int)value1 == (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
    case 1:
      if((int)value1 != (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
    case 2:
      if((int)value1 < (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
    case 3:
      if((int)value1 >= (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
    case 4:
      if((int)value1 > (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
    case 5:
      if((int)value1 <= (int)value2) {
        return frame->local_pc += this->branch_bytes;
      }
      else {
        return frame->local_pc+=3;
      }
      break;
  }
}

