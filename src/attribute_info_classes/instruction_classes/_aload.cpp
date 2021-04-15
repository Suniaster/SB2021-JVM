#include "../../../include/attribute_info_classes/instruction_classes/_aload.hpp"
using namespace Instructions;

InterfaceAload::InterfaceAload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}

int InterfaceAload::execute(Frame* frame){
  cout << "executando algum aload" << endl;
  uint64_t arrayref = frame->operand_stack.pop().first;
  uint64_t index = frame->operand_stack.pop().first;
  int index_int = (int) index;

  return frame->local_pc++;
}

/** load array classes **/
Iaload::Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Iaload::toString(){ return "iaload"; }

Laload::Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Laload::toString(){ return "laload"; }

Faload::Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Faload::toString(){ return "faload"; }

Daload::Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Daload::toString(){ return "daload"; }

Aaload::Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Aaload::toString(){ return "aaload"; }

Baload::Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Baload::toString(){ return "baload"; }

Caload::Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Caload::toString(){ return "caload"; }

Saload::Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Saload::toString(){ return "saload"; }