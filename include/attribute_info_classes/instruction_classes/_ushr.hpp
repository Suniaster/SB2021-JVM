#ifndef __INSTRUCTION_USHR_H__
#define __INSTRUCTION_USHR_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Ushr : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x78;
    uint8_t type;
    public:    
      Ushr(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}

#endif

