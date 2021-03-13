#include "../../../include/attribute_info_classes/instruction_classes/aload.hpp"
using namespace Instructions;


Aload::Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

void Aload::print(){
  cout << "\t\taload_" ;
  cout << hex << (int)this->opcode - 0x2a << endl;
}
