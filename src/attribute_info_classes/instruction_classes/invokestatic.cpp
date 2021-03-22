#include "../../../include/attribute_info_classes/instruction_classes/invokestatic.hpp"
using namespace Instructions;


InvokeStatic::InvokeStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeStatic::toString(){
  return this->createStringWithCPRef("invokestatic", this->index);
}
