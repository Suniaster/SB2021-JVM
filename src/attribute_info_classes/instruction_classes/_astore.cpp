#include "../../../include/attribute_info_classes/instruction_classes/_astore.hpp"
using namespace Instructions;

/** store array classes **/
Iastore::Iastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Iastore::toString(){ return "iastore"; }

Lastore::Lastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Lastore::toString(){ return "lastore"; }

Fastore::Fastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Fastore::toString(){ return "fastore"; }

Dastore::Dastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Dastore::toString(){ return "dastore"; }

Aastore::Aastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Aastore::toString(){ return "aastore"; }

Bastore::Bastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Bastore::toString(){ return "bastore"; }

Castore::Castore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Castore::toString(){ return "castore"; }

Sastore::Sastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
string Sastore::toString(){ return "sastore"; }