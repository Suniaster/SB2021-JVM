#ifndef __INSTRUCTION_ICONST_H__
#define __INSTRUCTION_ICONST_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Iconst : public BaseInstruction{
    private:
    public:    
      Iconst(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
  };
}

#endif
