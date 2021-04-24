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

    vector<uint64_t> dims;
    for(size_t i=0; i<this->dimensions;i+=1){
        dims.push_back(frame->operand_stack.pop().first);
    }
    // Todo: verificar dimensoes invalidas

    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->index);

    int heap_ref = ReferenceResolver::allocateArray(cp_entry->toString(), frame->thread->method_area, dims);

    frame->operand_stack.push(heap_ref, Reference);

    // switch (cp_entry->tag) {
    //     case 0x7:{
    //         string descript_name = cp_entry->toString();
    //         int heap_index = ReferenceResolver::resolveClassName(descript_name, frame->thread->method_area);
    //     }
    //     case 0xb:{
    //         string interface_name = cp_entry->toString();
    //         int heap_index = ReferenceResolver::resolveInterfaceName(interface_name, frame->thread->method_area);
    //     }
    //     default:{
    //         string array_type = cp_entry->toString();
    //     }
    // }


    // ArrayType* innerArray = new ArrayType(Reference);
    // innerArray->initialize(array_size_1.first);

    // ArrayType* outerArray = new ArrayType(JVMArray);
    // outerArray->initialize(array_size_2.first);

    // outerArray->insert(innerArray);
    // int heap_index = frame->thread->heap_ref->storeComponent(outerArray);
    // frame->operand_stack.push(heap_index, Reference);


    return frame->local_pc+=4;
}
