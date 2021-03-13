#ifndef __INSTRUCTION_ALOAD_N_H__
#define __INSTRUCTION_ALOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Aload : public BaseInstruction{
    private:
    public:    
      Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
