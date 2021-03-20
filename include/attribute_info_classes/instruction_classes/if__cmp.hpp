#ifndef __INSTRUCTION_IF__CMP_H__
#define __INSTRUCTION_IF__CMP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class If_cmp : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x9f;
    const vector<string> types = {
      "if_icmpeq", "if_icmpne", "if_icmplt", "if_icmpge",
      "if_icmpgt", "if_icmple", "if_acmpeq", "if_acmpne"
    };
    uint8_t type;
    uint16_t branch_bytes;
    public:    
      If_cmp(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif

