#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>

void PrimitiveType::print(){
  std::cout << "<" << this->data << ", " << this->type << ">";
}
