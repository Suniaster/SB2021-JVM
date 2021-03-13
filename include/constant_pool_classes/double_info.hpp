
#ifndef __DOUBLE_INFO_H__
#define __DOUBLE_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class DoubleInfo : public CpInfo{
      uint32_t high_bytes;
      uint32_t low_bytes;

    public:
      double returnDouble();
      DoubleInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
