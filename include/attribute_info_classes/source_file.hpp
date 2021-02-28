#ifndef __ATTR_SOURCE_FILE_INFO_H__
#define __ATTR_SOURCE_FILE_INFO_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class SourceFile : public AttributeInfo{
      uint16_t sourcefile_index;
    public:    
      SourceFile(
        ClassFile *class_file, 
        uint16_t attribute_name_index, 
        uint32_t attribute_length
      );

      void setInfo();
      void printInfo();

      string getFileName();
  };
}
#endif
