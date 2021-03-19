#ifndef __INSTRUCTION_SHL_H__
#define __INSTRUCTION_SHL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Shl : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x78;
    uint8_t type;
    public:    
      Shl(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

