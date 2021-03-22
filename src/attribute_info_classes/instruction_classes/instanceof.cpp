#include "../../../include/attribute_info_classes/instruction_classes/instanceof.hpp"
using namespace Instructions;


Instanceof::Instanceof(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string Instanceof::toString(){
  return this->createStringWithCPRef("instanceof", this->index);
}
