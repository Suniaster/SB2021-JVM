#ifndef __INSTRUCTION_CONST_H__
#define __INSTRUCTION_CONST_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class AconstNull : public BaseInstruction{
    public:
      AconstNull(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Iconst : public BaseInstruction{
    public:
      Iconst(Attribute::CodeAttribute* code_attr, uint8_t opcode); 
      string toString();
  };

  class Lconst : public BaseInstruction{
    public: 
      Lconst(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Fconst : public BaseInstruction{
    public:
      Fconst(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Dconst : public BaseInstruction{
    public:
      Dconst(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

}

#endif
