#include "../../../include/interpretador/types/component_type.hpp"
#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>

ComponentType::ComponentType(JVMType component_type){
  this->type = component_type;
}

ComponentType* ComponentType::getDefaultValue(JVMType type){
  if(type <= InterfaceReference){
    return new PrimitiveType(0, type);
  }

  throw std::runtime_error("creating componenttype without default value");
}

int ComponentType::getReference(){
  return this->heap_reference;
}

void ComponentType::setReference(int i){
  this->heap_reference = i;
}

void ComponentType::print(){
  std::cout << "ComponentType" << endl;
}

string ComponentType::toString(){
  return "ComponentType";
}