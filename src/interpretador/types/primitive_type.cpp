#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>

PrimitiveType::PrimitiveType(uint64_t x, JVMType type):ElementType(type){
  this->data =x;
};

void PrimitiveType::print(){
  std::cout << "<" << this->data << ", " << this->type << ">";
}
