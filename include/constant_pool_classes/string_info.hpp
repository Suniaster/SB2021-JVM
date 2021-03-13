
#ifndef __STRING_INFO_H__
#define __STRING_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class StringInfo : public CpInfo{
      uint16_t string_index;

    public:

      StringInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
