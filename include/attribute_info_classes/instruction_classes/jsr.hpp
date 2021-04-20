#ifndef __INSTRUCTION_JSR_H__
#define __INSTRUCTION_JSR_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Jsr : public BaseInstruction{
    private:
      uint16_t branch_bytes;
    public:    
      Jsr(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif
