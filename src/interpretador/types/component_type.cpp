#include "../../../include/interpretador/types/component_type.hpp"
#include "../../../include/interpretador/types/primitive_type.hpp"
#include "../../../include/interpretador/types/string_type.hpp"

#include <iostream>

ComponentType::ComponentType(JVMType component_type){
  this->type = component_type;
  this->heap_reference = -1;
}

ComponentType* ComponentType::getDefaultValue(JVMType type){
  if(type <= Reference){
    return new PrimitiveType(0, type);
  }

  if(type == JVMString) return new StringType(JVMString, ""); 

  throw std::runtime_error("creating componenttype without default value");
}

JVMType ComponentType::getTypeFromDescriptor(string descriptor){
  if(descriptor == "I") return Int;
  if(descriptor == "D") return Double;
  if(descriptor == "F") return Float;
  if(descriptor == "J") return Long;

  if(descriptor[0] == 'L') return Reference;
  return Reference;
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