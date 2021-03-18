#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
namespace Instructions{
  class BaseInstruction;
}

#include <cstdint>
#include "../code_attribute.hpp"
#include <sstream>

namespace Instructions{
  class BaseInstruction{
    protected:
      uint8_t opcode;
      Attribute::CodeAttribute* code_attr;
      string hexToString(int);
    public:    
      BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode);

      virtual void print();
      virtual string toString();
      static BaseInstruction* getInstance(Attribute::CodeAttribute* code_attr,uint8_t opcode);
  };
}

#endif
