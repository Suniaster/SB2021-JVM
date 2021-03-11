
#ifndef __LONG_INFO_H__
#define __LONG_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class LongInfo : public CpInfo{
      uint32_t high_bytes;
      uint32_t low_bytes;

    public:
      long long returnLong();
      LongInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
