#ifndef __INSTRUCTION_RETURN_H__
#define __INSTRUCTION_RETURN_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Return : public BaseInstruction{
    private:
    public:    
      Return(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
