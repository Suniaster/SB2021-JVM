#ifndef __INSTRUCTION_ASTORE_H__
#define __INSTRUCTION_ASTORE_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Astore : public BaseInstruction{
    private:
    public:    
      Astore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
