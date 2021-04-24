#ifndef __INSTRUCTION_ARRAYLENGTH_H__
#define __INSTRUCTION_ARRAYLENGTH_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class ArrayLength : public BaseInstruction{
    public:    
      ArrayLength(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      int execute(Frame*);
      string toString();
  };
}

#endif
