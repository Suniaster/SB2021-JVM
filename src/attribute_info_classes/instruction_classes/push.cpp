#include "../../../include/attribute_info_classes/instruction_classes/push.hpp"
using namespace Instructions;


Bipush::Bipush(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader* f = code_attr->class_file->file_reader;
  f->readBytes(1, this->param);
}

int Bipush::execute(Frame* frame){
    frame->operand_stack.push((int)this->param,Int);

    return frame->local_pc+=2;
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

int Sipush::execute(Frame* frame){
    frame->operand_stack.push((int)this->param,Int);

    return frame->local_pc+=3;
}

string Sipush::toString(){
  stringstream temp;
  temp << (int) this->param;
  return "sipush " +  temp.str();
}
