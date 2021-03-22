#ifndef __INSTRUCTION_INVOKE_INSTANCEOF_H__
#define __INSTRUCTION_INVOKE_INSTANCEOF_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Instanceof : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      Instanceof(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
