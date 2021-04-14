#ifndef __LOCAL_VARIABLE_H__
#define __LOCAL_VARIABLE_H__

#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

class LocalVariable{
  private:
    vector<uint64_t> local_variables;

  public:

    void initialize(uint32_t max_length);

    uint64_t get(int index);

    void insert(int index, uint64_t data);
    void print();
};

#endif