#ifndef __INSTRUCTION_RET_H__
#define __INSTRUCTION_RET_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Ret : public BaseInstruction{
    public:    
      uint8_t param;
      Ret(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

