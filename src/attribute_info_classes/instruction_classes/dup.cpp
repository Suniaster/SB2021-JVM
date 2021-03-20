#include "../../../include/attribute_info_classes/instruction_classes/dup.hpp"
using namespace Instructions;


Dup::Dup(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Dup::toString(){
  return "dup";
}

DupX1::DupX1(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){}
string DupX1::toString(){
  return "dup_x1";
}

DupX2::DupX2(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){}
string DupX2::toString(){
  return "dup_x2";
}

Dup2::Dup2(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){}
string Dup2::toString(){
  return "dup2";
}

Dup2X1::Dup2X1(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){}
string Dup2X1::toString(){
  return "dup2_x1";
}

Dup2X2::Dup2X2(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){}
string Dup2X2::toString(){
  return "dup2_x2";
}
