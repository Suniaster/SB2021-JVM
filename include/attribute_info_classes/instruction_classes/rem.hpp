#ifndef __INSTRUCTION_REM_H__
#define __INSTRUCTION_REM_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Rem : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x70;
    uint8_t type;
    public:    
      Rem(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

