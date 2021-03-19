#ifndef __INSTRUCTION_CMP_H__
#define __INSTRUCTION_CMP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Compare : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x85;
    const vector<string> types = {
      "lcmp", "fcmpl", 
      "fcmpg", "dcmpg"
    };
    uint8_t type;
    public:    
      Compare(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

