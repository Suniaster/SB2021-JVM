#include "../../../include/attribute_info_classes/instruction_classes/anewarray.hpp"

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
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->index);
    StringType* name = nullptr;

    switch (this->index) {
        case 0x7:{
            name = new StringType(cp_entry->toString());
            break;
        }
        case 0xb:{

            break;
        }
    }
    frame->local_pc+=2;
    return frame->local_pc+2;
}