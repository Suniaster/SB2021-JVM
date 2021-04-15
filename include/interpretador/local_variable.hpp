#ifndef __LOCAL_VARIABLE_H__
#define __LOCAL_VARIABLE_H__

#include <vector>
#include <iostream>
#include <cstdint>
#include "./types/primitive_type.hpp"

using namespace std;

class LocalVariable{
  private:
    vector<PrimitiveType*> local_variables;

  public:

    void initialize(uint32_t max_length);

    pair<uint64_t, JVMType> get(int index);

    void insert(int index, uint64_t data, JVMType type);
    void print();
};

#endif