#ifndef __INSTRUCTION_MONITOREXIT_H__
#define __INSTRUCTION_MONITOREXIT_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class MonitorExit : public BaseInstruction{
    public:    
      MonitorExit(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
