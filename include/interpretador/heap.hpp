#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include "./types/primitive_type.hpp"

using namespace std;

class Heap{
  private:
    vector<ComponentType*> heap_store;
    int size=0;

  public:
    ComponentType* getReference(int reference_id);
    int storeComponent(ComponentType*);
    int createPrimitiveTypeArray(int n_dimensions, JVMType arrayType);

};

#endif