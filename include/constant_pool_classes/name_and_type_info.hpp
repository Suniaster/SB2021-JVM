
#ifndef __NAME_AND_TYPE_INFO_H__
#define __NAME_AND_TYPE_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class NameAndTypeInfo : public CpInfo{
      uint16_t name_index;
      uint16_t descriptor_index;

    public:

      NameAndTypeInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
