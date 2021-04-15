#ifndef __INSTRUCTION__STORE_N_H__
#define __INSTRUCTION__STORE_N_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{

  class AbstractStore : public BaseInstruction{
    protected:
      bool is_n_class;
      uint8_t param;
    public:
      AbstractStore(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint8_t _store_opcode, uint8_t _storen_base_opcode);
      int execute(Frame* frame);
      
      virtual string getName() = 0;
      virtual JVMType getType() = 0;
      string toString();
  };

  class Istore : public AbstractStore{
    public:    
      Istore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Lstore : public AbstractStore{
    public:    
      Lstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };


  class Fstore : public AbstractStore{
    public:    
      Fstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Dstore : public AbstractStore{
    public:    
      Dstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };

  class Astore : public AbstractStore{
    public:    
      Astore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      JVMType getType();
  };
}

#endif
