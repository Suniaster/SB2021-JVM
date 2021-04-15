#ifndef __INSTRUCTION__ASTORE_N_H__
#define __INSTRUCTION__ASTORE_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  class InterfaceAstore : public BaseInstruction{
    public:    
      InterfaceAstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      virtual int execute(Frame* frame);
      virtual JVMType getType();
  };

  /** store array classes **/
  class Iastore : public InterfaceAstore{
    public:    
      Iastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Lastore : public InterfaceAstore{
    public:    
      Lastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Fastore : public InterfaceAstore{
    public:    
      Fastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Dastore : public InterfaceAstore{
    public:    
      Dastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Aastore : public InterfaceAstore{
    public:    
      Aastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Bastore : public InterfaceAstore{
    public:    
      Bastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Castore : public InterfaceAstore{
    public:    
      Castore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };

  class Sastore : public InterfaceAstore{
    public:    
      Sastore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      JVMType getType();
  };
}

#endif
