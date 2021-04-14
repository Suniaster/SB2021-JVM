#include "../../include/interpretador/local_variable.hpp"

void LocalVariable::initialize(uint32_t max_length){
 for (int i = 0; i < max_length; i++)
  {
    this->local_variables.push_back(0);
  }
}

void LocalVariable::print(){
  cout << "[";
  for (int i = 0; i < this->local_variables.size(); i++){
    cout << this->get(i) << ", ";
  }
  cout << "]"<< endl;
}

uint64_t LocalVariable::get(int index){
  return this->local_variables[index];
}

void LocalVariable::insert(int index, uint64_t data){
  this->local_variables[index] = data;
}