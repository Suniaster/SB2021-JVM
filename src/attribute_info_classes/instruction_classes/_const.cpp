#include "../../../include/attribute_info_classes/instruction_classes/_const.hpp"
using namespace Instructions;

AconstNull::AconstNull(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string AconstNull::toString(){
  return "aconst_null";
}

Iconst::Iconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Iconst::toString(){
  stringstream opcodeString;
  string className = "iconst_";
  if(this->opcode == 2){
    className += "m1";
  }
  else{
    opcodeString << (int)this->opcode-3;
  }
  return className + opcodeString.str();
}

Lconst::Lconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Lconst::toString(){
  return "lconst_undefined";
}

Fconst::Fconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

string Fconst::toString(){
  return "fconst_undefined";
}

Dconst::Dconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}
string Dconst::toString(){
  return "dconst_undefined";
}