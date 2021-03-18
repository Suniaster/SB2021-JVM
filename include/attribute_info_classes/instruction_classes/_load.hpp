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
      string toString();
  };

  class Iload : public AbstractLoad{
    private:
      uint8_t param;
    public:    
      Iload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };

  class Lload : public AbstractLoad{
    private:
      uint8_t param;
    public:    
      Lload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };


  class Fload : public AbstractLoad{
    private:
      uint8_t param;
    public:    
      Fload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };

  class Dload : public AbstractLoad{
    private:
      uint8_t param;
    public:    
      Dload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };

  class Aload : public AbstractLoad{
    private:
    public:    
      Aload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string getName();
  };
}

#endif
