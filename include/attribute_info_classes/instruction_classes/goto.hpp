#ifndef __INSTRUCTION_GOTO_H__
#define __INSTRUCTION_GOTO_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Goto : public BaseInstruction{
    private:
      uint16_t branch_bytes;
    public:    
      Goto(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif
