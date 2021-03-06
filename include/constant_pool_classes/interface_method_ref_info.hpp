
#ifndef __INTERFACE_METHOD_INFO_H__
#define __INTERFACE_METHOD_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class InterfaceMethodRefInfo : public CpInfo{
      uint16_t class_index;
      uint16_t name_and_type_index;
    public:

      InterfaceMethodRefInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
