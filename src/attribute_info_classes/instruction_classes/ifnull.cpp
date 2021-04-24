#include "../../../include/attribute_info_classes/instruction_classes/ifnull.hpp"
using namespace Instructions;


Ifnull::Ifnull(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
  this->code_attr->class_file->file_reader->readBytes(2, this->branch);
}

string Ifnull::toString(){
  return "ifnull " + 
  this->intToString(this->branch + this->pc) +
  " (" + this->intToSignedString(this->branch) +")";
}

int Ifnull::execute(Frame *frame) {
  int16_t branch_offset = this->branch;
  uint32_t base_adress = frame->local_pc;

  JVMType value = frame->operand_stack.pop().second;

  if (value == Reference && value == Null) {
    frame->local_pc = base_adress + branch_offset;
    return frame->local_pc;
  }
  else {
    return frame->local_pc += 3;
  } 
}
