#ifndef __ARRAY_TYPE_H__
#define __ARRAY_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

using namespace std;

class ArrayType : public ComponentType{
  private:
    vector<ComponentType*> data;
  public:

  void insert(ComponentType*);
  void print();
  uint64_t getValueAt(int index);
};

#endif
