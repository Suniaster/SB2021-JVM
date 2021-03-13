#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
namespace Instructions{
  class BaseInstruction;
}

#include <cstdint>
#include "../code_attribute.hpp"

namespace Instructions{
  class BaseInstruction{
    protected:
      uint8_t opcode;
      Attribute::CodeAttribute* code_attr;
    public:    
      BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode);

      virtual void print();

      static BaseInstruction* getInstance(Attribute::CodeAttribute* code_attr,uint8_t opcode);
  };
}

#endif
