#ifndef __INSTRUCTION_ANEWARRAY_H__
#define __INSTRUCTION_ANEWARRAY_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class ANewArray : public BaseInstruction{
    public:    
      uint16_t index;
      ANewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame* frame);
  };
}

#endif
