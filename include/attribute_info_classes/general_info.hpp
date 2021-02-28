#ifndef __ATTR_GENERAL_INFO_H__
#define __ATTR_GENERAL_INFO_H__

#include "../attribute_info.hpp"

namespace Attribute{
  class GeneralInfo : public AttributeInfo{
    public:    
      vector<uint8_t> info;
      GeneralInfo(
        ClassFile *class_file, 
        uint16_t attribute_name_index, 
        uint32_t attribute_length
      );

      void setInfo();
      void printInfo();
  };
}
#endif
