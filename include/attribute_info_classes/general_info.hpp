#ifndef __ATTR_GENERAL_INFO_H__
#define __ATTR_GENERAL_INFO_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class GeneralInfo : public AttributeInfo{
    public:    
      vector<uint8_t> info;
      GeneralInfo(AttrInitialValue initial_value);

      void printInfo(int n_tabs);
  };
}
#endif
