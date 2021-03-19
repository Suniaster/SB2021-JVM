#include "../../../include/attribute_info_classes/instruction_classes/getfield.hpp"


using namespace Instructions;

GetField::GetField(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->indexbyte);    
}



void GetField::print(){
  cout << "\t\tgetfield #" ;
  cout << hex << (int)this->indexbyte << endl;
}