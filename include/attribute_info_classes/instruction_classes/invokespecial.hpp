#ifndef __INSTRUCTION_INVOKE_SPECIAL_H__
#define __INSTRUCTION_INVOKE_SPECIAL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class InvokeSpecial : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      InvokeSpecial(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
