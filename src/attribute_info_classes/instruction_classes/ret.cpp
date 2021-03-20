#include "../../../include/attribute_info_classes/instruction_classes/ret.hpp"
using namespace Instructions;


Ret::Ret(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
  this->code_attr->class_file->file_reader->readBytes(1, this->param);
}

string Ret::toString(){
  return "ret "+ this->intToString(this->param);
}
