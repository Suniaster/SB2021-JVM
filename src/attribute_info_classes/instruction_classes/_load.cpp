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
  pair<uint64_t, JVMType> value = frame->local_variables.get(this->param);
  if(value.second == Byte){
    value.first = (int8_t)value.first;
  }
  if(value.second == Short){
    value.first = (int16_t)value.first;
  }
  frame->operand_stack.push(value.first, value.second);

  if(this->is_n_class)
    frame->local_pc += 1;
  else frame->local_pc += 2;

  return frame->local_pc;
}

Iload::Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x15, 0x1a){}
string Iload::getName(){ return "iload"; }
JVMType Iload::getType(){return Int;}

Lload::Lload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x16, 0x1e){}
string Lload::getName(){ return "lload"; }
JVMType Lload::getType(){return Long;}

Fload::Fload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x17, 0x22){}
string Fload::getName(){ return "fload"; }
JVMType Fload::getType(){return Float;}

Dload::Dload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x18, 0x26){}
string Dload::getName(){ return "dload"; }
JVMType Dload::getType(){return Double;}

Aload::Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :AbstractLoad(code_attr, opcode, 0x19, 0x2a){}
string Aload::getName(){ return "aload"; }
JVMType Aload::getType(){return Reference;}