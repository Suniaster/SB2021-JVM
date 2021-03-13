
#ifndef __METHOD_HANDLE_INFO_H__
#define __METHOD_HANDLE_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class MethodHandleInfo : public CpInfo{
      uint8_t reference_kind;
      uint16_t reference_index;
    public:

      MethodHandleInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
