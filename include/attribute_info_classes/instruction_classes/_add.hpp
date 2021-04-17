#ifndef __INSTRUCTION_ADD_H__
#define __INSTRUCTION_ADD_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Add : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x60;
    uint8_t type;
    public:    
      Add(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame*);
  };
}


#endif
