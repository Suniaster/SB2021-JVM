#ifndef __INSTRUCTION__ASTORE_N_H__
#define __INSTRUCTION__ASTORE_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  /** store array classes **/
  class Iastore : public BaseInstruction{
    public:    
      Iastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Lastore : public BaseInstruction{
    public:    
      Lastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Fastore : public BaseInstruction{
    public:    
      Fastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Dastore : public BaseInstruction{
    public:    
      Dastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Aastore : public BaseInstruction{
    public:    
      Aastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Bastore : public BaseInstruction{
    public:    
      Bastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Castore : public BaseInstruction{
    public:    
      Castore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Sastore : public BaseInstruction{
    public:    
      Sastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
