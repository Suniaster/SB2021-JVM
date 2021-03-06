
#ifndef __CLASS_INFO_H__
#define __CLASS_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class ClassInfo : public CpInfo{
      uint16_t name_index;

    public:

      ClassInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
