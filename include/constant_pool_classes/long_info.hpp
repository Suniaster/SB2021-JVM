
#ifndef __LONG_INFO_H__
#define __LONG_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class LongInfo : public CpInfo{
      uint32_t bytes;

    public:

      LongInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
