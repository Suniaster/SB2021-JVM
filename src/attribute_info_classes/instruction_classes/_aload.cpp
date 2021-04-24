#include "../../../include/attribute_info_classes/instruction_classes/_aload.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
using namespace Instructions;

InterfaceAload::InterfaceAload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
JVMType InterfaceAload::getType(){return Reference;}

int InterfaceAload::execute(Frame* frame){
  uint64_t index = frame->operand_stack.pop().first;
  uint64_t arrayref = frame->operand_stack.pop().first;
  
  ArrayType* array = (ArrayType*)frame->thread->heap_ref->getReference(arrayref);
  PrimitiveType* element = (PrimitiveType*)array->getIndex(index);
  frame->operand_stack.push(element->data, element->type);

  return frame->local_pc++;
}

/** load array classes **/
Iaload::Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Iaload::toString(){ return "iaload"; }
JVMType Iaload::getType(){return Int;}

Laload::Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Laload::toString(){ return "laload"; }
JVMType Laload::getType(){return Long;}

Faload::Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Faload::toString(){ return "faload"; }
JVMType Faload::getType(){return Float;}

Daload::Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Daload::toString(){ return "daload"; }
JVMType Daload::getType(){return Double;}

Aaload::Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Aaload::toString(){ return "aaload"; }
JVMType Aaload::getType(){return Reference;}

Baload::Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Baload::toString(){ return "baload"; }
JVMType Baload::getType(){return Byte;}

Caload::Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Caload::toString(){ return "caload"; }
JVMType Caload::getType(){return Char;}

Saload::Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAload(code_attr, opcode){}
string Saload::toString(){ return "saload"; }
JVMType Saload::getType(){return Short;}