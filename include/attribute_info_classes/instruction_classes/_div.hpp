#ifndef __INSTRUCTION_DIV_H__
#define __INSTRUCTION_DIV_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Div : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x6c;
    uint8_t type;
    public:    
      Div(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif
