#include "../../../include/attribute_info_classes/instruction_classes/iload.hpp"
using namespace Instructions;


Iload::Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

void Iload::print(){
  cout << "\t\tiload_" ;
  cout << hex << (int)this->opcode - 0x1a << endl;
}
