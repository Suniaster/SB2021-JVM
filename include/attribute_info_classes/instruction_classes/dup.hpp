#ifndef __INSTRUCTION_DUP_H__
#define __INSTRUCTION_DUP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Dup : public BaseInstruction{
    public:    
      Dup(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
