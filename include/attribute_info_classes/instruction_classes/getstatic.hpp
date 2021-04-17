#ifndef __INSTRUCTION_GETSTATIC_H__
#define __INSTRUCTION_GETSTATIC_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class GetStatic : public BaseInstruction{
    private:
    
      uint16_t indexbyte;
    public:    
      GetStatic(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame* frame);
  };
}

#endif
