#include "../../../include/attribute_info_classes/code_attribute_classes/exception_table.hpp"

using namespace Attribute;

CodeException::CodeException(CodeAttribute* code_attr){
  this->code_attr = code_attr;
  FileReader* f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->start_pc);
  f_reader->readBytes(2, this->end_pc);
  f_reader->readBytes(2, this->handler_pc);
  f_reader->readBytes(2, this->catch_type);
}

pair<int, int> CodeException::isPcHandled(int pc) {
  pair<int,int> retVal(-1,-1);
  
  if (pc >= this->start_pc && pc <= this->end_pc) {
    retVal.first = this->handler_pc;
    retVal.second = this->catch_type;
    return retVal;
  }
  else
    return retVal;
}