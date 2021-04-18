#include "../../../include/interpretador/types/component_type.hpp"
#include "../../../include/interpretador/types/primitive_type.hpp"
#include "../../../include/interpretador/types/string_type.hpp"

#include <iostream>

ComponentType::ComponentType(JVMType component_type){
  this->type = component_type;
  this->heap_reference = -1;
}

ComponentType* ComponentType::getDefaultValue(JVMType type){
  if(type <= InterfaceReference){
    return new PrimitiveType(0, type);
  }

  if(type == StringReference) return new StringType(JVMString, ""); 

  throw std::runtime_error("creating componenttype without default value");
}

JVMType ComponentType::getTypeFromDescriptor(string descriptor){
  if(descriptor == "Ljava/lang/String;") return StringReference;
  if(descriptor == "I") return Int;

  return Int;
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