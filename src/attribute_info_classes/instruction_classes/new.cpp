#include "../../../include/attribute_info_classes/instruction_classes/new.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/types/jvm_object.hpp"
using namespace Instructions;


New::New(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string New::toString(){
  return this->createStringWithCPRef("new", this->index);
}

int New::execute(Frame* frame){
  MethodArea* m = frame->thread->method_area;
  string class_name = frame->current_method->class_file->getConstantPoolEntry(this->index)->toString();

  ReferenceResolver::resolveClassName(class_name, m);

  JVMObject* newObject = new JVMObject(class_name);
  newObject->initializeFields();

  int heap_ref = Heap::getInstance()->storeComponent(newObject);
  frame->operand_stack.push(heap_ref, Reference);

  // cout << newObject->toString() << endl;
  frame->local_pc+=3;
  return frame->local_pc;
}