#include "../../../include/attribute_info_classes/instruction_classes/ifnonnull.hpp"
using namespace Instructions;


Ifnonnull::Ifnonnull(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
  this->code_attr->class_file->file_reader->readBytes(2, this->branch);
}

string Ifnonnull::toString(){
  return "ifnonnull " + 
  this->intToString(this->branch + this->pc) +
  " (" + this->intToSignedString(this->branch) +")";
}
