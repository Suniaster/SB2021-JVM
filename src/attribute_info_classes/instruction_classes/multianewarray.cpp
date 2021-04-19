#include "../../../include/attribute_info_classes/instruction_classes/multianewarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
using namespace Instructions;


MultiANewArray::MultiANewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
  FileReader *f = this->code_attr->class_file->file_reader;
  f->readBytes(2, this->index);
  f->readBytes(1, this->dimensions);
}

string MultiANewArray::toString(){
  return this->createStringWithCPRef("multianewarray", this->index) + 
  " dimensions: " + this->intToString(this->dimensions);
}

int MultiANewArray::execute(Frame *frame) {
    pair<uint64_t,JVMType> array_size_1 = frame->operand_stack.pop();
    pair<uint64_t,JVMType> array_size_2 = frame->operand_stack.pop();

    if ((int)array_size_1.first <0 || (int)array_size_2.first <0){
        throw std::runtime_error("wrong array size multianewarray");
    }




    ArrayType* innerArray = new ArrayType(JVMString);
    innerArray->initialize(array_size_1.first);

    ArrayType* outerArray = new ArrayType(JVMArray);
    outerArray->initialize(array_size_2.first);

    int heap_index = frame->thread->heap_ref->storeComponent(outerArray);
    frame->operand_stack.push(heap_index, Reference);

    frame->local_pc+=4;
    return frame->local_pc+4;


}
