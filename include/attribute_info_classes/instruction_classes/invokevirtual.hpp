#ifndef __INSTRUCTION_INVOKE_VIRTUAL_H__
#define __INSTRUCTION_INVOKE_VIRTUAL_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class InvokeVirtual : public BaseInstruction{
    private:
      uint16_t index;
    public:    
      InvokeVirtual(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
