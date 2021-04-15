#ifndef __COMPONENT_TYPE_H__
#define __COMPONENT_TYPE_H__
#include <vector>
#include <cstdint>

using namespace std;

class ComponentType{
    int heap_reference;
  public:
    void setReference(int);
    int getReference();
    virtual void print();
};

#endif
