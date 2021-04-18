#ifndef __INSTRUCTION_NEWARRAY_H__
#define __INSTRUCTION_NEWARRAY_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class NewArray : public BaseInstruction{
    public:
      uint8_t atype;
      string getATypeName();
      NewArray(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      int execute(Frame* frame);
      string toString();
  };
}

#endif
