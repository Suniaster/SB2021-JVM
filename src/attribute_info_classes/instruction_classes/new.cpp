#include "../../../include/attribute_info_classes/instruction_classes/new.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/interpretador/types/jvm_object.hpp"
#include "../../../include/interpretador/types/string_type.hpp"

#include "../../../include/interpretador/types/exception_type.hpp"
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

  if(ReferenceResolver::resolveClassName(class_name, m) >= 0){
    JVMObject* newObject = new JVMObject(class_name);
    newObject->initializeFields();

    int heap_ref = Heap::getInstance()->storeComponent(newObject);
    frame->operand_stack.push(heap_ref, Reference);
  }
  else if(class_name == "java/lang/String" || class_name == "java/lang/StringBuilder"){
    StringType* newString = new StringType("");
    int heap_ref = Heap::getInstance()->storeComponent(newString);
    frame->operand_stack.push(heap_ref, Reference);
  }
  else if (class_name.find("Exception") != std::string::npos || class_name.find("Error") != std::string::npos) {
    ExceptionType* e = new ExceptionType(class_name);
    int heap_ref = Heap::getInstance()->storeComponent(e);
    frame->operand_stack.push(heap_ref, Reference);
  }
  else{
    frame->operand_stack.push(-1, Reference);
  }

  frame->local_pc+=3;
  return frame->local_pc;
}