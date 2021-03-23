#ifndef __INSTRUCTION_JSR_W_H__
#define __INSTRUCTION_JSR_W_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Jsr_W : public BaseInstruction{
    private:
      int32_t branch_bytes;
    public:    
      Jsr_W(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
