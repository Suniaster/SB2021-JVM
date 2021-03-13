
#ifndef __METHOD_TYPE_INFO_H__
#define __METHOD_TYPE_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class MethodTypeInfo : public CpInfo{
      
      uint16_t descriptor_index;
    public:

      MethodTypeInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
