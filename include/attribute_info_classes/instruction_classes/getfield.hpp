#ifndef __INSTRUCTION_GETFIELD_H__
#define __INSTRUCTION_GETFIELD_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class GetField : public BaseInstruction{
    private:
      uint16_t indexbyte;
    public:    
      GetField(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
