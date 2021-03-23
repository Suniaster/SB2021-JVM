
#ifndef __UTF8_INFO_H__
#define __UTF8_INFO_H__

#include "../cp_info.hpp"

namespace CP{
  class Utf8Info : public CpInfo{
      uint16_t length;
      uint8_t *bytes;


    public:

      Utf8Info(ClassFile *class_file);
      ~Utf8Info();
      string returnString();
      void setInfo();
      void printInfo();
      string toString();
  };
}
#endif
