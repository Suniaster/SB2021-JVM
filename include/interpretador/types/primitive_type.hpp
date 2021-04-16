#ifndef __PRIMITIVE_TYPE_H__
#define __PRIMITIVE_TYPE_H__

#include "./element_type.hpp"
#include <cstdint>

using namespace std;

class PrimitiveType: public ElementType{
  public:
    uint64_t data;
    PrimitiveType(uint64_t x, JVMType type);
    void print();
};



#endif
