#ifndef __EXCEPTION_TABLE_H__
#define __EXCEPTION_TABLE_H__
namespace Attribute{
  class CodeException;
}

#include <cstdint>
#include "../code_attribute.hpp"

namespace Attribute{
  class CodeException{
    private:
      uint16_t start_pc;
      uint16_t end_pc;
      uint16_t handler_pc;
      uint16_t catch_type;

      CodeAttribute* code_attr;
    public:    
      CodeException(CodeAttribute* code_attr);
      
      void setInfo();
  };
}

#endif
