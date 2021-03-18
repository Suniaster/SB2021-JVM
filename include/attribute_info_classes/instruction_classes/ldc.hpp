#ifndef __INSTRUCTION_LDC_H__
#define __INSTRUCTION_LDC_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Ldc : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Ldc(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class LdcW : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      LdcW(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Ldc2W : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Ldc2W(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
