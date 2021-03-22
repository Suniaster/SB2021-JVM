#include "../../../include/attribute_info_classes/instruction_classes/putstatic.hpp"


using namespace Instructions;

PutStatic::PutStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);    
}



string PutStatic::toString(){
  return "putstatic " + this->code_attr->class_file->getConstantPoolEntry(this->param)->toString();
}