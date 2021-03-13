#include "../../../include/attribute_info_classes/instruction_classes/lcd.hpp"
using namespace Instructions;


Lcd::Lcd(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(1, this->index);    
}

void Lcd::print(){
  cout << "\t\tlcd #" ;
  cout << hex << (int)this->index << endl;
}
