#include "../../../include/attribute_info_classes/instruction_classes/invokespecial.hpp"
using namespace Instructions;


InvokeSpecial::InvokeSpecial(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

void InvokeSpecial::print(){
  cout << "\t\tinvokespecial #" ;
  cout << hex << (int)this->index << endl;
}
