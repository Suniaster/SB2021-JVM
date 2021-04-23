#include "../../../include/attribute_info_classes/instruction_classes/getfield.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/types/jvm_object.hpp"

using namespace Instructions;

GetField::GetField(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->indexbyte);    
}


string GetField::toString(){
  return this->createStringWithCPRef("getfield", this->indexbyte);
}

int GetField::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->indexbyte)->toString();
  string field_name = ReferenceResolver::separateSymbol(symbolic_ref, ".").second;
  // TODO: fazer checagem de tipo

  pair<uint64_t, JVMType> objref = frame->operand_stack.pop();
  if(objref.second != Reference) throw std::runtime_error("TypeError: Objref is not a reference");

  JVMObject* obj  = (JVMObject*)Heap::getInstance()->getReference(objref.first);

  JVMField* f = obj->getField(field_name);
  PrimitiveType* data = (PrimitiveType*)f->getData();

  frame->operand_stack.push(data->data, data->type);

  frame->local_pc+=3;
  return frame->local_pc;
}