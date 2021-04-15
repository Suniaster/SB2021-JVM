#include "../../../include/interpretador/types/component_type.hpp"
#include <iostream>
int ComponentType::getReference(){
  return this->heap_reference;
}

void ComponentType::setReference(int i){
  this->heap_reference = i;
}

void ComponentType::print(){
  std::cout << "ComponentType";
}
