
#ifndef __FIELD_REF_INFO_H__
#define __FIELD_REF_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class FieldRefInfo : public CpInfo{
      uint16_t class_index;
      uint16_t name_and_type_index;
    public:
    
      FieldRefInfo(ClassFile *class_file);
      void setInfo();
      void printInfo();
  };
}
#endif
