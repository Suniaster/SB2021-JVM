#include "../../../include/attribute_info_classes/instruction_classes/astore.hpp"
using namespace Instructions;


Astore::Astore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

void Astore::print(){
  cout << "\t\tastore_" ;
  cout << hex << (int)this->opcode-75 << endl;
}
