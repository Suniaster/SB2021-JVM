#include "../../../include/attribute_info_classes/instruction_classes/iconst.hpp"
using namespace Instructions;


Iconst::Iconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

void Iconst::print(){
  if(this->opcode == 2){
    cout << "\t\ticonst_m1" ;
    cout << endl;
  }
  else{
    cout << "\t\ticonst_" ;
    cout << dec << (int)this->opcode-3 << endl;
  }
}
