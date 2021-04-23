#ifndef __INSTRUCTION_NEW_H__
#define __INSTRUCTION_NEW_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class New : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      New(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();

      int execute(Frame*);
  };
}

#endif
