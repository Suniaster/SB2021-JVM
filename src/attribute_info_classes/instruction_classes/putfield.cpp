#include "../../../include/attribute_info_classes/instruction_classes/putfield.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/types/jvm_object.hpp"

using namespace Instructions;

PutField::PutField(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->indexbyte);    
}

string PutField::toString(){
  return this->createStringWithCPRef("putfield", this->indexbyte);
}

int PutField::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->indexbyte)->toString();
  string field_name = ReferenceResolver::separateSymbol(symbolic_ref, ".").second;
  pair<uint64_t, JVMType> value = frame->operand_stack.pop();
  pair<uint64_t, JVMType> objref = frame->operand_stack.pop();

  if(objref.second != Reference) throw std::runtime_error("TypeError: Objref is not a reference");

  JVMObject* obj  = (JVMObject*)Heap::getInstance()->getReference(objref.first);

  JVMField* f = obj->getField(field_name);
  f->setData(new PrimitiveType(value.first, value.second));

  frame->local_pc+=3;
  return frame->local_pc;
}