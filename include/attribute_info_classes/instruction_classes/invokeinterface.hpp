#ifndef __INSTRUCTION_INVOKE_INTERFACE_H__
#define __INSTRUCTION_INVOKE_INTERFACE_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class InvokeInterface : public BaseInstruction{
    private:
      uint16_t index;
      uint8_t count;
      uint8_t zero;
    public:    
      InvokeInterface(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
