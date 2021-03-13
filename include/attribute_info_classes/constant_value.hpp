#ifndef __ATTR_CONST_VAL_H__
#define __ATTR_CONST_VAL_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class ConstantValue : public AttributeInfo{
    public:    
      uint16_t constantvalue_index;
      ConstantValue(AttrInitialValue initial_val);

      void printInfo();
  };
}

#endif
