#ifndef __INSTRUCTION_MULTIANEWARRAY_H__
#define __INSTRUCTION_MULTIANEWARRAY_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class MultiANewArray : public BaseInstruction{
    public:    
      uint8_t dimensions;
      uint16_t index;
      MultiANewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame* frame);
  };
}

#endif
