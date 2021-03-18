#include "../../../include/attribute_info_classes/instruction_classes/_load.hpp"
using namespace Instructions;


Aload::Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Aload::toString(){
  return "aload_"+this->hexToString(this->opcode - 0x2a);
}


Iload::Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Iload::toString(){
  return "iload_"+this->hexToString(this->opcode - 0x1a);
}
