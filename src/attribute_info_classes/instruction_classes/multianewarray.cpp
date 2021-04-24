#include "../../../include/attribute_info_classes/instruction_classes/multianewarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"

#include <algorithm>
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

    vector<uint64_t> dims;
    for(size_t i=0; i<this->dimensions;i+=1){
      dims.push_back(frame->operand_stack.pop().first);
    }
    reverse(dims.begin(), dims.end());
    // Todo: verificar dimensoes invalidas

    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->index);

    int heap_ref = ReferenceResolver::allocateArray(cp_entry->toString(), frame->thread->method_area, dims);

    frame->operand_stack.push(heap_ref, Reference);

    return frame->local_pc+=4;
}
