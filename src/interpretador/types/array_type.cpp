#include "../../../include/interpretador/types/array_type.hpp"
#include "../../../include/interpretador/heap.hpp"
#include <iostream>
#include <sstream>

using namespace std;

ArrayType::ArrayType(JVMType content_type):ComponentType(JVMArray){
  this->content_type = content_type;
}

void ArrayType::print(){
  cout << "[";
  for(uint16_t i=0;i<this->data.size();i++){
    cout << this->data[i]->toString() << " (" << this->data[i]->type <<")";
    if(this->data[i]->type == Reference){
      PrimitiveType* p = (PrimitiveType*)this->data[i];
      ComponentType* ref = Heap::getInstance()->getReference(p->data);
      cout << "'" << ref->toString() << "'";
    }
    cout << ", ";
  }
  cout << "]" << endl;
}

string ArrayType::toString(){
  stringstream paramString;
  paramString << "[";
  for(uint16_t i=0;i<this->data.size();i++){
    paramString << this->data[i]->toString();
    paramString << ", ";
  }
  paramString << "]";
  return paramString.str();
}

void ArrayType::insert(ComponentType* toinsert){
  this->data.push_back(toinsert);
}
int ArrayType::getLength(){
  return this->data.size();
}
void ArrayType::setIndexAsPrimitiveType(int index, uint64_t value, JVMType type){
  if((uint)index > this->data.size()) throw std::runtime_error("ArrayError: Acessando indice invalido");
  if(type != this->content_type){ 
    // throw std::runtime_error("TypeError: Mudando elemento para tipo invalido");
  }

  ComponentType* oldValue = this->data[index];

  this->data[index] =  new PrimitiveType(value, type);
}

int ArrayType::getIndexReference(int index){
  return this->data[index]->getReference();
}

ComponentType* ArrayType::getIndex(int i){
  if(i >= this->data.size() ) throw std::runtime_error("ArrayError: Acessando indice invalido");
  return this->data[i];
}

pair<uint64_t,JVMType> ArrayType::getIndexAsAsPrimitiveType(int index){
  pair<uint64_t,JVMType> returnVal;
  PrimitiveType* p = (PrimitiveType*)this->data[index];
  returnVal.first = p->data;
  returnVal.second = p->type;
  return returnVal;
}

void ArrayType::initialize(int max_length) {

    for (std::size_t i = 0; i < max_length; ++i) {
        ComponentType* default_value = ComponentType::getDefaultValue(this->content_type);
        this->insert(default_value);
    }
    
}