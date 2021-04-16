#include "../../../include/attribute_info_classes/instruction_classes/getstatic.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"

using namespace Instructions;

GetStatic::GetStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->indexbyte);    
}

string GetStatic::toString(){
  return "getstatic #" + this->intToString(this->indexbyte) +
  " <" + this->code_attr->class_file->getConstantPoolEntry(this->indexbyte)->toString() + ">";
}

int GetStatic::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->indexbyte)->toString();

  JVMField* f = ReferenceResolver::resolveStaticFieldSymbolicReference(
    symbolic_ref, 
    frame->thread->heap_ref, 
    frame->thread->method_area
  );

  // TODO: verificacao de tipo
  PrimitiveType* field_data = (PrimitiveType*)f->getData();

  frame->operand_stack.push(field_data->data, field_data->type);

  frame->local_pc += 3;
  return frame->local_pc;
}