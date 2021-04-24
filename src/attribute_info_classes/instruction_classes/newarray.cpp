#include "../../../include/attribute_info_classes/instruction_classes/newarray.hpp"
#include "../../../include/interpretador/types/array_type.hpp"
using namespace Instructions;


NewArray::NewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
    this->code_attr->class_file->file_reader->readBytes(1, this->atype);
}
string NewArray::getATypeName(){
  switch (this->atype)
  {
  case 4:
    return "boolean";
  case 5:
    return "char";
  case 6:
    return "float";
  case 7:
    return "double";
  case 8:
    return "byte";
  case 9:
    return "short";
  case 10:
    return "int";
  case 11:
    return "long";
  default:
    return "no_type";
  }
}

string NewArray::toString(){
  return "newarray " + this->intToString(this->atype) + 
  + " (" +this->getATypeName() + ")";
}

int NewArray::execute(Frame *frame) {
    pair<uint64_t,JVMType> array_size = frame->operand_stack.pop();

    if (array_size.first < 0)
        throw std::runtime_error("NegativeArraySizeException");

    JVMType array_type;

    switch (this->atype)
    {
        case 4:
            array_type = Boolean;
            break;
        case 5:
            array_type = Char;
            break;
        case 6:
            array_type = Float;
            break;
        case 7:
            array_type = Double;
            break;
        case 8:
            array_type = Byte;
            break;
        case 9:
            array_type = Short;
            break;
        case 10:
            array_type = Int;
            break;
        case 11:
            array_type = Long;
            break;
        default:
            throw std::runtime_error("invalid array type");
    }
    ArrayType* arrayType = new ArrayType(array_type);
    arrayType->initialize(array_size.first);
    int reference_index = frame->thread->heap_ref->storeComponent(arrayType);
    frame->operand_stack.push(reference_index, Reference);


    return frame->local_pc+=2;
}