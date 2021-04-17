#ifndef __INSTRUCTION_PUSH_H__
#define __INSTRUCTION_PUSH_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Bipush : public BaseInstruction{
    public:
      uint8_t param;
      Bipush(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      int execute(Frame *frame);
      string toString();
  };

  class Sipush : public BaseInstruction{
    public:
      uint16_t param;
      Sipush(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
