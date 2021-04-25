#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include "./types/primitive_type.hpp"

using namespace std;

class Heap{
  private:
    static Heap* instance;
    vector<ComponentType*> heap_store;
    int size=0;
    Heap(){}
    ~Heap();

  public:
    
    ComponentType* getReference(int reference_id);
    int storeComponent(ComponentType*);
    int createPrimitiveTypeArray(int n_dimensions, JVMType arrayType);
    static Heap* getInstance();
    static void releaseInstance();
};

#endif
