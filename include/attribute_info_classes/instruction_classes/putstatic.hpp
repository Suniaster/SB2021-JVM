#ifndef __INSTRUCTION_PUTSTATIC_H__
#define __INSTRUCTION_PUTSTATIC_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class PutStatic : public BaseInstruction{
    private:
      uint16_t param;
    public:    
      PutStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
