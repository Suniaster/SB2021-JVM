#ifndef __ATTR_SOURCE_FILE_INFO_H__
#define __ATTR_SOURCE_FILE_INFO_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class SourceFile : public AttributeInfo{
      uint16_t sourcefile_index;
    public:    
      SourceFile(AttrInitialValue initial_value);

      void printInfo();

      string getFileName();
  };
}
#endif
