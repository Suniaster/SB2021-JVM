#include "../../../include/attribute_info_classes/instruction_classes/ldc.hpp"
using namespace Instructions;


Ldc::Ldc(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(1, this->param);    
}

string Ldc::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc #" + paramString.str() + " <" + cp_val->toString() + ">";
}


LdcW::LdcW(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);    
}

string LdcW::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc_w #" + paramString.str() + " <" + cp_val->toString() + ">";
}

Ldc2W::Ldc2W(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);    
}

string Ldc2W::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc2_w #" + paramString.str() + " <" + cp_val->toString() + ">";
}

int Ldc2W::execute(Frame* frame){
  uint64_t value = frame->current_method->class_file->getConstantPoolEntry(this->param)->getValue();

  frame->operand_stack.push(value);

  frame->local_pc += 3;
  return frame->local_pc;
}
