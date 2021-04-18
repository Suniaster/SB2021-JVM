#include "../../../include/attribute_info_classes/instruction_classes/putstatic.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"

using namespace Instructions;

PutStatic::PutStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);    
}

string PutStatic::toString(){
  return "putstatic #" + this->intToString(this->param) +
  " <" + this->code_attr->class_file->getConstantPoolEntry(this->param)->toString() + ">";
}

int PutStatic::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->param)->toString();

  pair<uint64_t,JVMType> value = frame->operand_stack.pop();

  cout << value.first<< " " << value.second << endl;
  JVMField* f = ReferenceResolver::resolveStaticFieldSymbolicReference(
    symbolic_ref,
    frame->thread->method_area
  );
  
  f->setData(new PrimitiveType(value.first, value.second));

  frame->local_pc += 3;
  return frame->local_pc;
}