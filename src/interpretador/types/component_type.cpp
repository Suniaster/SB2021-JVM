#include "../../../include/interpretador/types/component_type.hpp"
#include <iostream>


ComponentType::ComponentType(JVMType component_type){
  this->type = component_type;
}

int ComponentType::getReference(){
  return this->heap_reference;
}

void ComponentType::setReference(int i){
  this->heap_reference = i;
}

void ComponentType::print(){
  std::cout << "ComponentType";
}
