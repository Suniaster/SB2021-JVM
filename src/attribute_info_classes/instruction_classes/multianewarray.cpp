#include "../../../include/attribute_info_classes/instruction_classes/multianewarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
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
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->index);
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


    ArrayType* innerArray = new ArrayType(Reference);
    innerArray->initialize(array_size_1.first);

    ArrayType* outerArray = new ArrayType(JVMArray);
    outerArray->initialize(array_size_2.first);

    outerArray->insert(innerArray);
    int heap_index = frame->thread->heap_ref->storeComponent(outerArray);
    frame->operand_stack.push(heap_index, Reference);


    return frame->local_pc+4;


}
