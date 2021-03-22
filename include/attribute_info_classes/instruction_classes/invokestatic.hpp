#ifndef __INSTRUCTION_INVOKE_INVOKESTATIC_H__
#define __INSTRUCTION_INVOKE_INVOKESTATIC_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class InvokeStatic : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      InvokeStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
