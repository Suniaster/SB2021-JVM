#ifndef __INSTRUCTION_IFNULL_H__
#define __INSTRUCTION_IFNULL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Ifnull : public BaseInstruction{
    public:    
      int16_t branch;
      Ifnull(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif
