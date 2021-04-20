#ifndef __INSTRUCTION_CMP_H__
#define __INSTRUCTION_CMP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Lcmp : public BaseInstruction{
    public:    
      Lcmp(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
  
  class Fcmp : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x95;
    uint8_t type;
    public:    
      Fcmp(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
  class Dcmp : public BaseInstruction{
    const uint8_t BASE_OPCODE = 0x97;
    uint8_t type;
    public:    
      Dcmp(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
}

#endif

