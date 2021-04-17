#include "../../../include/interpretador/types/jvm_field.hpp"
#include "../../../include/interpretador/heap.hpp"
#include <iostream>



JVMField::JVMField(FieldInfo* field_info):ComponentType(JVMFIELD){
  this->field_info_ref = field_info;
  this->field_name = field_info->getName();
  string field_descriptor = field_info->getDescriptor();

  // TODO: transformar descriptor em tipo certo;
  this->data = ComponentType::getDefaultValue(Int);

  Heap::getInstance()->storeComponent(this->data);
}

string JVMField::toString(){
  return this->field_name;
}

ComponentType* JVMField::getData(){
  return this->data;
};

void JVMField::setData(ComponentType* newData){
  // TODO: fazer checagem de tipo dinamica
  if(newData->type != this->data->type ){
    throw std::runtime_error("TypeError: tipo atribuido ao field invalido");
  }
  Heap* heap = Heap::getInstance();
  heap->storeComponent(newData);

  this->data = newData;
}