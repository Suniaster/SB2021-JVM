#ifndef __INSTRUCTION_SHR_H__
#define __INSTRUCTION_SHR_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Shr : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x7a;
    uint8_t type;
    public:    
      Shr(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif

