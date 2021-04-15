#include "../../../include/attribute_info_classes/instruction_classes/_astore.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
using namespace Instructions;

InterfaceAstore::InterfaceAstore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :BaseInstruction(code_attr, opcode){}
JVMType InterfaceAstore::getType(){return Reference;}

int InterfaceAstore::execute(Frame* frame){
  uint64_t arrayref, index, value;
  arrayref  = frame->operand_stack.pop().first;
  index     = frame->operand_stack.pop().first;
  value     = frame->operand_stack.pop().first;

  /// Testando
  // index = 2;
  // value = 23;
  // arrayref = frame->thread->heap_ref->createPrimitiveTypeArray(4, Float);

  ArrayType* array = (ArrayType*)frame->thread->heap_ref->getReference(arrayref);
  array->setIndexAsPrimitiveType(index, value, this->getType());

  array->print();
  return frame->local_pc++;
}

/** store array classes **/
Iastore::Iastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Iastore::toString(){ return "iastore"; }
JVMType Iastore::getType(){return Int;}

Lastore::Lastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Lastore::toString(){ return "lastore"; }
JVMType Lastore::getType(){return Long;}

Fastore::Fastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Fastore::toString(){ return "fastore"; }
JVMType Fastore::getType(){return Float;}

Dastore::Dastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Dastore::toString(){ return "dastore"; }
JVMType Dastore::getType(){return Double;}

Aastore::Aastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Aastore::toString(){ return "aastore"; }
JVMType Aastore::getType(){return Reference;}

Bastore::Bastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Bastore::toString(){ return "bastore"; }
JVMType Bastore::getType(){return Byte;}

Castore::Castore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Castore::toString(){ return "castore"; }
JVMType Castore::getType(){return Char;}

Sastore::Sastore(Attribute::CodeAttribute* code_attr, uint8_t opcode)
  :InterfaceAstore(code_attr, opcode){}
string Sastore::toString(){ return "sastore"; }
JVMType Sastore::getType(){return Int;}