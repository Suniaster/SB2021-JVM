#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
namespace Instructions{
  class BaseInstruction;
}

#include <cstdint>
#include "../code_attribute.hpp"

namespace Instructions{
  class BaseInstruction{
    private:
      uint8_t bytecode;
      Attribute::CodeAttribute* code_attr;
    public:    
      BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t bytecode);

      virtual void print();
      virtual void readOperands();
      static BaseInstruction* getInstance(Attribute::CodeAttribute* code_attr,uint8_t bytecode);
  };
}

#endif
