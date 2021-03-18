#include "../../../include/attribute_info_classes/instruction_classes/_const.hpp"
using namespace Instructions;

string AconstNull::toString(){
  return "aconst_null";
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

string Lconst::toString(){
  return "lconst_undefined";
}

string Fconst::toString(){
  return "fconst_undefined";
}

string Dconst::toString(){
  return "dconst_undefined";
}