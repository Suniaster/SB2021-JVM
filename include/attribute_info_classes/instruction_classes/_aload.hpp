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
      virtual JVMType getType();
  };

  class Iaload : public InterfaceAload{
    public:    
      Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Laload : public InterfaceAload{
    public:    
      Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Faload : public InterfaceAload{
    public:    
      Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Daload : public InterfaceAload{
    public:    
      Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Aaload : public InterfaceAload{
    public:    
      Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Baload : public InterfaceAload{
    public:    
      Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Caload : public InterfaceAload{
    public:    
      Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Saload : public InterfaceAload{
    public:    
      Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };
}

#endif
