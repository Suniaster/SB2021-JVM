#include "../../../include/attribute_info_classes/instruction_classes/wide.hpp"

using namespace Instructions;


Wide::Wide(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){ 
    FileReader *f = this->code_attr->class_file->file_reader;
    f->readBytes(1, this->instruction_opcode);
    BaseInstruction::getInstance(this->code_attr, this->instruction_opcode, 0);

    f->readBytes(2, this->index);
    if(this->instruction_opcode == 0x84){ // iinc
      f->readBytes(2, this->const_bytes);
    }
}

void Wide::print(int n_tabs){
  cout << "wide -> " + this->instruction->toString() 
  + "; #" + this->intToString(this->index) +
  this->code_attr->class_file->getConstantPoolEntry(this->index)->toString();
}

Wide::~Wide(){
  delete this->instruction;
}