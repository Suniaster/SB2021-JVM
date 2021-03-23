#ifndef __INSTRUCTION_ATHROW_H__
#define __INSTRUCTION_ATHROW_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Athrow : public BaseInstruction{
    private:
    public:    
      Athrow(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
