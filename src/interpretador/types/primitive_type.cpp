#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>
#include <sstream>

PrimitiveType::PrimitiveType(uint64_t x, JVMType type):ElementType(type){
  this->data =x;
};

void PrimitiveType::print(){
  std::cout << "<" << this->data << ", " << this->type << ">";
}

string PrimitiveType::toString(){
  stringstream paramString;
  paramString << "<" << this->data << ", " << this->type << ">";
  return paramString.str();
}