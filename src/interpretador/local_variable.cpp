#include "../../include/interpretador/local_variable.hpp"

void LocalVariable::initialize(uint32_t max_length){
  for (std::size_t i = 0; i < max_length; i++){
    PrimitiveType* defaultValue = new PrimitiveType(0, Int);
    this->local_variables.push_back(defaultValue);
  }
}

void LocalVariable::print(){
  cout << "[";
  for (std::size_t i = 0; i < this->local_variables.size(); i++){
    PrimitiveType p(this->get(i).first, this->get(i).second);
    cout << p.toString() << ", ";
  }
  cout << "]"<< endl;
}

pair<uint64_t, JVMType> LocalVariable::get(int index){
  pair<uint64_t, JVMType> returnVal;
  returnVal.first = this->local_variables[index]->data;
  returnVal.second = this->local_variables[index]->type;
  return returnVal;
}

void LocalVariable::insert(int index, uint64_t data, JVMType type){
  this->local_variables[index]->data = data;
  this->local_variables[index]->type = type;
}
