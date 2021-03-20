#ifndef __INSTRUCTION_SWAP_H__
#define __INSTRUCTION_SWAP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Swap : public BaseInstruction{
    public:    
      Swap(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
