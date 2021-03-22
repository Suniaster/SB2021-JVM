#include "../../../include/attribute_info_classes/instruction_classes/newarray.hpp"
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
