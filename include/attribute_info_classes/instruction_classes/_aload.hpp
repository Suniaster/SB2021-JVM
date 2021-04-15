#ifndef __INSTRUCTION__ALOAD_N_H__
#define __INSTRUCTION__ALOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  /** Load array classes **/
  class InterfaceAload : public BaseInstruction{
    public:    
      InterfaceAload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      int execute(Frame* frame);
  };

  class Iaload : public InterfaceAload{
    public:    
      Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Laload : public InterfaceAload{
    public:    
      Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Faload : public InterfaceAload{
    public:    
      Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Daload : public InterfaceAload{
    public:    
      Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Aaload : public InterfaceAload{
    public:    
      Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Baload : public InterfaceAload{
    public:    
      Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Caload : public InterfaceAload{
    public:    
      Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Saload : public InterfaceAload{
    public:    
      Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
