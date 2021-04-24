#include "../../../include/attribute_info_classes/instruction_classes/invokevirtual.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/invoke_simulation.hpp"
using namespace Instructions;


InvokeVirtual::InvokeVirtual(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeVirtual::toString(){
  return this->createStringWithCPRef("invokevirtual", this->index);
}


int InvokeVirtual::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->index)->toString();
  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_ref, ".");

  if(symbolic_ref == "java/io/PrintStream.println"){
    InvokeSimulation::println(frame, this->index);
  }
  else{
    frame->thread->invokeInstanceMethod(names.first, names.second);
  }


  frame->local_pc += 3;
  return frame->local_pc;
}