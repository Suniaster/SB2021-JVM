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
