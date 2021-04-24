#ifndef __INSTRUCTION_GOTO_W_H__
#define __INSTRUCTION_GOTO_W_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Goto_W : public BaseInstruction{
    private:
      int32_t branch_bytes;
    public:    
      Goto_W(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif
