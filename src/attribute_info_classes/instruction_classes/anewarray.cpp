#include "../../../include/attribute_info_classes/instruction_classes/anewarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
using namespace Instructions;


ANewArray::ANewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string ANewArray::toString(){
  return this->createStringWithCPRef("anewarray", this->index);
}

int ANewArray::execute(Frame *frame) {

    vector<uint64_t> dims;
    dims.push_back(frame->operand_stack.pop().first);
    string class_name = this->code_attr->class_file->getConstantPoolEntry(this->index)->toString();
    
    int heap_ref = ReferenceResolver::allocateArray("[L"+class_name, frame->thread->method_area, dims);
    frame->operand_stack.push(heap_ref, Reference);

    return frame->local_pc+=3;
}