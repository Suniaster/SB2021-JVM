#include "../../../include/attribute_info_classes/instruction_classes/invokevirtual.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/invoke_simulation.hpp"
#include "../../../include/constant_pool_classes/method_ref_info.hpp"

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
  CP::MethodRefInfo* ref_info = (CP::MethodRefInfo*)frame->current_method->class_file->getConstantPoolEntry(this->index);
  string symbolic_ref = ref_info->toString();
  string descriptor = ref_info->getDescriptor();
  
  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_ref, ".");

  if(symbolic_ref == "java/io/PrintStream.println"){
    InvokeSimulation::println(frame, this->index);
  }
  else if(names.first == "java/lang/StringBuilder"){
    InvokeSimulation::stringMethod(names.second, frame, this->index);
  }
  else{
    frame->thread->invokeInstanceMethod(names.first, names.second, descriptor);
  }


  frame->local_pc += 3;
  return frame->local_pc;
}