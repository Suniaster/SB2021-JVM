#include "../../../include/attribute_info_classes/instruction_classes/getstatic.hpp"


using namespace Instructions;

GetStatic::GetStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->indexbyte);    
}



string GetStatic::toString(){
  return "getstatic " + this->code_attr->class_file->getConstantPoolEntry(this->indexbyte)->toString();
}