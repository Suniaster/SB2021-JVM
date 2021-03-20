#include "../../../include/attribute_info_classes/instruction_classes/push.hpp"
using namespace Instructions;


Bipush::Bipush(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){  
  FileReader* f = code_attr->class_file->file_reader;
  f->readBytes(1, this->param);
}

string Bipush::toString(){
  stringstream temp;
  temp << (int) this->param;
  return "bipush " +  temp.str();
}

Sipush::Sipush(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){  
  FileReader* f = code_attr->class_file->file_reader;
  f->readBytes(2, this->param);
}

string Sipush::toString(){
  stringstream temp;
  temp << (int) this->param;
  return "sipush " +  temp.str();
}
