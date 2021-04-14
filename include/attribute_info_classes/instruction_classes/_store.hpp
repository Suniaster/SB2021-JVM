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

      virtual string getName() = 0;
      string toString();
  };

  class Istore : public AbstractStore{
    private:
      uint8_t param;
    public:    
      Istore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };

  class Lstore : public AbstractStore{
    private:
      uint8_t param;
    public:    
      Lstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };


  class Fstore : public AbstractStore{
    private:
      uint8_t param;
    public:    
      Fstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };

  class Dstore : public AbstractStore{
    private:
      uint8_t param;
    public:    
      Dstore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
      int execute(Frame* frame);
  };

  class Astore : public AbstractStore{
    private:
    public:    
      Astore(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };
}

#endif
