#ifndef __LOCAL_VARIABLE_H__
#define __LOCAL_VARIABLE_H__

#include <vector>
#include <iostream>
#include "../JVMTypes/jvm_type.hpp"

class LocalVariable
{
  private:
    vector<JVMType *> local_variables;

  public:
    void initialize(uint32_t max_length);
    template <typename T>
    T get(int index);

    template <typename T>
    void insert(int index, T data);
    void print();
};

template <typename T>
T LocalVariable::get(int index)
{
  return ((JVMType_t<T> *)this->local_variables[index])->data;
}

template <typename T>
void LocalVariable::insert(int index, T data)
{
  if (index == this->local_variables.size())
  {
    JVMType_t<T> *value = new JVMType_t<T>();
    value->data = data;
    this->local_variables.push_back(value);
  }
  else
  {
    ((JVMType_t<T> *)this->local_variables[index])->data = data;
  }
}
#endif