#include "../../../include/attribute_info_classes/instruction_classes/invokestatic.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/constant_pool_classes/method_ref_info.hpp"
using namespace Instructions;


InvokeStatic::InvokeStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeStatic::toString(){
  return this->createStringWithCPRef("invokestatic", this->index);
}

int InvokeStatic::execute(Frame* frame){
  
  CP::MethodRefInfo* ref_info = (CP::MethodRefInfo*)frame->current_method->class_file->getConstantPoolEntry(this->index);
  string symbolic_ref = ref_info->toString();
  string descriptor = ref_info->getDescriptor();

  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_ref, ".");

  frame->thread->invokeStaticMethod(names.first, names.second, descriptor);

  return frame->local_pc+=3;
}