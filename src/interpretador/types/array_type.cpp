#include "../../../include/interpretador/types/array_type.hpp"
#include <iostream>

using namespace std;

void ArrayType::print(){
  cout << "Array" << endl;
}

void ArrayType::insert(ComponentType* toinsert){
  this->data.push_back(toinsert);
}