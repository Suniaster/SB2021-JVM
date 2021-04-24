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


    pair<uint64_t,JVMType> array_size = frame->operand_stack.pop();
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->index);
    ArrayType* arrayType = new ArrayType(Reference);
    arrayType->initialize(array_size.first);
    switch (cp_entry->tag) {
        case 0x7:{
            string class_name = cp_entry->toString();
            int heap_index = ReferenceResolver::resolveClassName(class_name, frame->thread->method_area);
        }
        case 0xb:{
            string interface_name = cp_entry->toString();
            int heap_index = ReferenceResolver::resolveClassName(interface_name, frame->thread->method_area);
        }
        default:{
            string array_type = cp_entry->toString();
        }
    }

    int array_index = frame->thread->heap_ref->storeComponent(arrayType);
    frame->operand_stack.push(array_index, Reference);


    return frame->local_pc+=3;
}