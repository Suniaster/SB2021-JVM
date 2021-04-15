#ifndef __ELEMENT_TYPE_H__
#define __ELEMENT_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

class ElementType : public ComponentType{};

class ClassType: public ElementType{};

class InterfaceType: public ElementType{};

#endif
