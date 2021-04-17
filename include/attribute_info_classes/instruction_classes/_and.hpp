#ifndef __INSTRUCTION_AND_H__
#define __INSTRUCTION_AND_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class And : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x7e;
    uint8_t type;
    public:    
      And(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif

