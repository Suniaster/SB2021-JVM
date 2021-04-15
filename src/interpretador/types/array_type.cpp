#include "../../../include/interpretador/types/array_type.hpp"
#include <iostream>

using namespace std;

void ArrayType::print(){
  cout << "[";
  for(uint16_t i=0;i<this->data.size();i++){
    this->data[i]->print();
    cout << ", ";
  }
  cout << "]" << endl;
}

void ArrayType::insert(ComponentType* toinsert){
  this->data.push_back(toinsert);
}

void ArrayType::setIndexAsPrimitiveType(int index, uint64_t value, JVMType type){
  ComponentType* oldValue = this->data[index];
  delete oldValue;
  this->data[index] =  new PrimitiveType(value, type);
}

int ArrayType::getIndexReference(int index){
  return this->data[index]->getReference();
}