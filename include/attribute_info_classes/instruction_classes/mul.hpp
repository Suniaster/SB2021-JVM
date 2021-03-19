#ifndef __INSTRUCTION_MUL_H__
#define __INSTRUCTION_MUL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Mul : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x68;
    uint8_t type;
    public:    
      Mul(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

