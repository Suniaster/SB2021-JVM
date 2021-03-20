#ifndef __INSTRUCTION_POP_H__
#define __INSTRUCTION_POP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Pop : public BaseInstruction{
    public:    
      Pop(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
  class Pop2 : public BaseInstruction{
    public:    
      Pop2(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
