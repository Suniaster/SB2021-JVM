#include "../../../include/attribute_info_classes/instruction_classes/anewarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
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

    if (this->index != 0x7 && this->index != 0xb){
        throw std::runtime_error("anewarray wrong index code");
    }


    ArrayType* arrayType = new ArrayType(JVMString);
    arrayType->initialize(array_size.first);
    int heap_index = frame->thread->heap_ref->storeComponent(arrayType);
    frame->operand_stack.push(heap_index, Reference);

    frame->local_pc+=3;
    return frame->local_pc+3;
}