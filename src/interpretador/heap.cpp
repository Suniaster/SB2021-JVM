#include "../../include/interpretador/heap.hpp"
#include "../../include/interpretador/types/array_type.hpp"
#include "../../include/interpretador/types/primitive_type.hpp"
#include <stdexcept>
#include <iostream>

Heap* Heap::instance = NULL;

Heap* Heap::getInstance(){
  if(Heap::instance == NULL){
    Heap::instance = new Heap();
  }
  return Heap::instance;
}
void Heap::releaseInstance(){
  if(Heap::instance != NULL){
    delete Heap::instance;
    Heap::instance=NULL;
  }
}

int Heap::createPrimitiveTypeArray(int length, JVMType arrayType){
  ArrayType* newArray = new ArrayType(arrayType);
  for(int i=0;i<length;i++){
    PrimitiveType* defaultValue = new PrimitiveType(0, arrayType);
    this->storeComponent(defaultValue);
    newArray->insert(defaultValue);
  }
  this->storeComponent(newArray);
  return newArray->getReference();
}

int Heap::storeComponent(ComponentType* toStore){
  
  if(toStore->getReference() >= 0) return toStore->getReference();

  this->heap_store.push_back(toStore);
  int newElementIndex = this->heap_store.size()-1;
  toStore->setReference(newElementIndex);
  return newElementIndex;
}

Heap::~Heap(){
  for(uint i=0 ;i<this->heap_store.size(); i++){
    ComponentType* c = this->heap_store[i];
    delete c;
  }
  this->heap_store.clear();
}

ComponentType* Heap::getReference(int reference_id){
  if(reference_id < 0) throw runtime_error("HeapError: Invalid heap access.");
  return this->heap_store[reference_id];
}