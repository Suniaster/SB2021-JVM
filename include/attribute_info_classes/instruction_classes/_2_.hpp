#ifndef __INSTRUCTION__2__H__
#define __INSTRUCTION__2__H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class TypeConversion : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x85;
    const vector<string> types = {
      "i2l", "i2f", "i2d",
      "l2i", "l2f", "l2d",
      "f2i", "f2l", "f2d",
      "d2i", "d2l", "d2f",
      "l2b", "i2c", "i2s"
    };
    uint8_t type;
    public:    
      TypeConversion(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

