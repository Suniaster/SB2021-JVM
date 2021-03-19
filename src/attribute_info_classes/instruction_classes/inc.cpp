#include "../../../include/attribute_info_classes/instruction_classes/inc.hpp"
using namespace Instructions;


Inc::Inc(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
  FileReader *f = this->code_attr->class_file->file_reader;
  f->readBytes(1, this->_index);
  f->readBytes(1, this->_const);

}

string Inc::toString(){
  return BaseInstruction::getTypePrefix(this->type) + 
  "inc " +
  this->intToString(this->_index) +
  " by " +
  this->intToString(this->_const)  ;
}

