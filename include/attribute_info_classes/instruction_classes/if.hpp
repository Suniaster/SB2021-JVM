#ifndef __INSTRUCTION_IF_H__
#define __INSTRUCTION_IF_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class If : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x99;
    const vector<string> types = {
      "ifeq", "ifne", "iflt",
      "ifge", "ifgt", "ifle"
    };
    uint8_t type;
    uint16_t branch_bytes;
    public:    
      If(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif

