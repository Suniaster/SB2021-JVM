#ifndef __INSTRUCTION_WIDE_H__
#define __INSTRUCTION_WIDE_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Wide : public BaseInstruction{
    public:    
      uint8_t instruction_opcode;
      Instructions::BaseInstruction* instruction;
      uint16_t index;
      uint16_t const_bytes;
      Wide(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      
      void print(int);
      ~Wide();
  };
}

#endif
