#ifndef __INSTRUCTION__LOAD_N_H__
#define __INSTRUCTION__LOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Aload : public BaseInstruction{
    private:
    public:    
      Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Iload : public BaseInstruction{
    private:
    public:    
      Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
