#include "../../../include/attribute_info_classes/instruction_classes/athrow.hpp"
using namespace Instructions;


Athrow::Athrow(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

void Athrow::print(){
  cout << "\t\tathrow" ;
  cout << endl;
}
