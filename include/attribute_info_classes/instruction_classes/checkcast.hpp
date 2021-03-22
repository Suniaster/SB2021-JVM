#ifndef __INSTRUCTION_INVOKE_CHECKCAST_H__
#define __INSTRUCTION_INVOKE_CHECKCAST_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class CheckCast : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      CheckCast(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
