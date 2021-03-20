#ifndef __INSTRUCTION__ALOAD_N_H__
#define __INSTRUCTION__ALOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  /** Load array classes **/
  class Iaload : public BaseInstruction{
    public:    
      Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Laload : public BaseInstruction{
    public:    
      Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Faload : public BaseInstruction{
    public:    
      Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Daload : public BaseInstruction{
    public:    
      Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Aaload : public BaseInstruction{
    public:    
      Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Baload : public BaseInstruction{
    public:    
      Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Caload : public BaseInstruction{
    public:    
      Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Saload : public BaseInstruction{
    public:    
      Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
