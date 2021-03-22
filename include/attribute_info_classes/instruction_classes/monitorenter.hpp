#ifndef __INSTRUCTION_MONITORENTER_H__
#define __INSTRUCTION_MONITORENTER_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class MonitorEnter : public BaseInstruction{
    public:    
      MonitorEnter(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
