#ifndef __INSTRUCTION_INC_H__
#define __INSTRUCTION_INC_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Inc : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x84;
    uint8_t type;
    uint8_t _index;
    uint8_t _const;
    public:    
      Inc(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

