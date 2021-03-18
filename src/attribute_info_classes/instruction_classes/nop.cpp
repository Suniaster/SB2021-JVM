#include "../../../include/attribute_info_classes/instruction_classes/nop.hpp"
using namespace Instructions;


Nop::Nop(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

void Nop::print(){
  cout << "nop";
  cout << endl;
}
