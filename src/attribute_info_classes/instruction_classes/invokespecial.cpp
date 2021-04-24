#include "../../../include/attribute_info_classes/instruction_classes/invokespecial.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
using namespace Instructions;


InvokeSpecial::InvokeSpecial(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeSpecial::toString(){
  return this->createStringWithCPRef("invokespecial", this->index);
}

int InvokeSpecial::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->index)->toString();
  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_ref, ".");

  // if(ReferenceResolver::isValidClassName(names.first))
  frame->thread->invokeInstanceMethod(names.first, names.second);

  return frame->local_pc+=3;
}