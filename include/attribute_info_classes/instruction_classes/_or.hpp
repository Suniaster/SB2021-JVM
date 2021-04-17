#ifndef __INSTRUCTION_OR_H__
#define __INSTRUCTION_OR_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Or : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x80;
    uint8_t type;
    public:    
      Or(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif

