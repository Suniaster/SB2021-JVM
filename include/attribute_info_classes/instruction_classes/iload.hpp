#ifndef __INSTRUCTION_ILOAD_N_H__
#define __INSTRUCTION_ILOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Iload : public BaseInstruction{
    private:
    public:    
      Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
