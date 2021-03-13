
#ifndef __FLOAT_INFO_H__
#define __FLOAT_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class FloatInfo : public CpInfo{
      uint32_t bytes;

    public:

      FloatInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
