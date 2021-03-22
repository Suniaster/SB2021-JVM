#include "../../../include/attribute_info_classes/instruction_classes/invokeinterface.hpp"
using namespace Instructions;


InvokeInterface::InvokeInterface(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
  f_reader->readBytes(1, this->count);
  f_reader->readBytes(1, this->zero);
}

string InvokeInterface::toString(){
  return this->createStringWithCPRef("invokeinterface", this->index) 
  + " count: " + this->intToString(this->count);
}
