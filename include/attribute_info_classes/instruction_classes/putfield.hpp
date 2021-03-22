#ifndef __INSTRUCTION_PUTFIELD_H__
#define __INSTRUCTION_PUTFIELD_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class PutField : public BaseInstruction{
    private:
      uint16_t indexbyte;
    public:    
      PutField(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
