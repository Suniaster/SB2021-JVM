#ifndef __ELEMENT_TYPE_H__
#define __ELEMENT_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

class ElementType : public ComponentType{
  public:
    ElementType(JVMType type):ComponentType(type){}
};

class ClassInstanceType: public ElementType{

};

class InterfaceType: public ElementType{};

#endif
