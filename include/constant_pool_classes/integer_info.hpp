
#ifndef __INTEGER_INFO_H__
#define __INTEGER_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class IntegerInfo : public CpInfo{
      uint32_t bytes;

    public:

      IntegerInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
