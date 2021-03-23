#ifndef __ATTR_SOURCE_FILE_INFO_H__
#define __ATTR_SOURCE_FILE_INFO_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class SourceFile : public AttributeInfo{
      uint16_t sourcefile_index;
      string removeSubString(string initial, string sub_string);
    public:
      SourceFile(AttrInitialValue initial_value);

      void printInfo(int n_tabs);

      string getFileName();
  };
}
#endif
