#ifndef __ATTR_EXCEPTIONS_H__
#define __ATTR_EXCEPTIONS_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class Exceptions : public AttributeInfo{
    public:    
      uint16_t number_of_exceptions;
      vector<uint16_t> exception_index_table;
      
      Exceptions(AttrInitialValue initial_val);

      void printInfo();
  };
}

#endif
