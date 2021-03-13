#ifndef __ATTR_SYNTHETIC_H__
#define __ATTR_SYNTHETIC_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class Synthetic : public AttributeInfo{
    public:
      Synthetic(AttrInitialValue initial_val);

      void printInfo();
  };
}

#endif
