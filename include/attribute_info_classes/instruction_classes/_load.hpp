#ifndef __INSTRUCTION__LOAD_N_H__
#define __INSTRUCTION__LOAD_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  class AbstractLoad : public BaseInstruction{
    protected:
      bool is_n_class;
      uint8_t param;
    public:
      AbstractLoad(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint8_t _load_opcode, uint8_t _loadn_base_opcode);

      virtual string getName() = 0;
      virtual JVMType getType() = 0;
      string toString();
      int execute(Frame* frame);
  };

  class Iload : public AbstractLoad{
    public:    
      Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Lload : public AbstractLoad{
    public:    
      Lload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };


  class Fload : public AbstractLoad{
    public:    
      Fload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Dload : public AbstractLoad{
    public:    
      Dload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Aload : public AbstractLoad{
    public:    
      Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };
}

#endif
