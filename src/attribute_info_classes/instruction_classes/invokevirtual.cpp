#include "../../../include/attribute_info_classes/instruction_classes/invokevirtual.hpp"
using namespace Instructions;


InvokeVirtual::InvokeVirtual(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeVirtual::toString(){
  return this->createStringWithCPRef("invokevirtual", this->index);
}
