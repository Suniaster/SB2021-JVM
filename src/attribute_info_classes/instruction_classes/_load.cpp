#include "../../../include/attribute_info_classes/instruction_classes/_load.hpp"
using namespace Instructions;

AbstractLoad::AbstractLoad(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint8_t _load_opcode, uint8_t _loadn_base_opcode)
  :BaseInstruction(code_attr, opcode){
  
  this->is_n_class = !(opcode == _load_opcode);

  if(! this->is_n_class )
    this->code_attr->class_file->file_reader->readBytes(1, this->param);
  else
    this->param = this->opcode - _loadn_base_opcode;
}

string AbstractLoad::toString(){
  if(this->is_n_class)
    return this->getName() + "_" + this->hexToString(this->param);
  else
    return this->getName() + " " + this->hexToString(this->param);
}

int AbstractLoad::execute(Frame* frame){
  uint64_t value = frame->local_variables.get(this->param);
  frame->operand_stack.push(value);

  if(this->is_n_class)
    frame->local_pc += 1;
  else frame->local_pc += 2;

  return frame->local_pc;
}

Iload::Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x15, 0x1a){}

string Iload::getName(){ return "iload"; }

Lload::Lload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x16, 0x1e){}

string Lload::getName(){ return "lload"; }

Fload::Fload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x17, 0x22){}

string Fload::getName(){ return "fload"; }

Dload::Dload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x18, 0x26){}

string Dload::getName(){ return "dload"; }


Aload::Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x19, 0x2a){}
string Aload::getName(){ return "aload"; }
