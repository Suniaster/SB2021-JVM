#ifndef __PRIMITIVE_TYPE_H__
#define __PRIMITIVE_TYPE_H__

#include "./element_type.hpp"
#include <cstdint>

using namespace std;


typedef enum{
  Null, Long, Double, Byte, Short, Boolean, Char, Int, Float, Reference, ReturnAdress
} JVMType;


class PrimitiveType: public ElementType{
  public:
    uint64_t data;
    PrimitiveType(uint64_t x, JVMType type);
    void print();
    string toString();
};



#endif
