
#ifndef __METHOD_REF_INFO_H__
#define __METHOD_REF_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class MethodRefInfo : public CpInfo{
      uint16_t class_index;
      uint16_t name_and_type_index;
    public:
    
      MethodRefInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
      string toString();
      string getDescriptor();
  };
}
#endif
