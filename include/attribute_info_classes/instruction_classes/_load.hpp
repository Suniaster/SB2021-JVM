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

  class Iaload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Iaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Laload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Laload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Faload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Faload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Daload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Daload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Aaload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Aaload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Baload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Baload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Caload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Caload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };

  class Saload : public BaseInstruction{
    private:
      uint8_t param;
    public:    
      Saload(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
  };
}

#endif
