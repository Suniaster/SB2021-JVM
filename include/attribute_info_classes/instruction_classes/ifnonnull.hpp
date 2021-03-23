#ifndef __INSTRUCTION_IFNONNULL_H__
#define __INSTRUCTION_IFNONNULL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Ifnonnull : public BaseInstruction{
    public:    
      int16_t branch;
      Ifnonnull(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
