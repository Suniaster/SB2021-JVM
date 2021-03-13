
#ifndef __UNUSED_INFO_H__
#define __UNUSED_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class UnusedInfo : public CpInfo{


    public:
      UnusedInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
