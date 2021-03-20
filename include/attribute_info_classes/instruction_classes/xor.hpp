#ifndef __INSTRUCTION_XOR_H__
#define __INSTRUCTION_XOR_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Xor : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x82;
    uint8_t type;
    public:    
      Xor(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

