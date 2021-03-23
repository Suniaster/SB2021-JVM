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
