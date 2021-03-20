#ifndef __INSTRUCTION_NEG_H__
#define __INSTRUCTION_NEG_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Neg : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x74;
    uint8_t type;
    public:    
      Neg(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

