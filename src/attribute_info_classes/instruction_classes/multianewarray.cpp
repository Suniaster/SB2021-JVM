#include "../../../include/attribute_info_classes/instruction_classes/multianewarray.hpp"
using namespace Instructions;


MultiANewArray::MultiANewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
  FileReader *f = this->code_attr->class_file->file_reader;
  f->readBytes(2, this->index);
  f->readBytes(1, this->dimensions);
}

string MultiANewArray::toString(){
  return this->createStringWithCPRef("multianewarray", this->index) + 
  " dimensions: " + this->intToString(this->dimensions);
}
