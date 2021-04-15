#ifndef __PRIMITIVE_TYPE_H__
#define __PRIMITIVE_TYPE_H__

#include "./element_type.hpp"
#include <cstdint>

using namespace std;

typedef enum{
  Long, Double, Byte, Short, Boolean, Char, Int, Float, Reference, ReturnAdress
} JVMType;

class PrimitiveType: public ElementType{
  private:
    JVMType type;
    uint64_t data;
  public:
    PrimitiveType::PrimitiveType(uint64_t x, JVMType type){
      this->type = type;
      this->data =x;
    };
};



#endif
