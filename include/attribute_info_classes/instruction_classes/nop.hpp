#ifndef __INSTRUCTION_NOP_H__
#define __INSTRUCTION_NOP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Nop : public BaseInstruction{
    public:    
      Nop(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
