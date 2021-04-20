#ifndef __INSTRUCTION_SUB_H__
#define __INSTRUCTION_SUB_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Sub : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x64;
    uint8_t type;
    public:    
      Sub(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif
