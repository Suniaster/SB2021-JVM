
#ifndef __INVOKE_DYNAMIC_INFO_H__
#define __INVOKE_DYNAMIC_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class InvokeDynamicInfo : public CpInfo{
      uint16_t bootstrap_method_attr_index;
      uint16_t name_and_type_index;

    public:

      InvokeDynamicInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
