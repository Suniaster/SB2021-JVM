#ifndef __INSTRUCTION__RETURN_H__
#define __INSTRUCTION__RETURN_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class _Return : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0xac;
    uint8_t type;
    public:    
      _Return(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

