#include "../../../include/attribute_info_classes/instruction_classes/new.hpp"
using namespace Instructions;


New::New(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

void New::print(){
  cout << "\t\tnew #" ;
  cout << hex << (int)this->index << endl;
}
