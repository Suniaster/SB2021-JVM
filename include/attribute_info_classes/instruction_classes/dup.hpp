#ifndef __INSTRUCTION_DUP_H__
#define __INSTRUCTION_DUP_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Dup : public BaseInstruction{
    public:    
      Dup(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };

  class DupX1 : public BaseInstruction{
    public:    
      DupX1(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
  class DupX2 : public BaseInstruction{
    public:    
      DupX2(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };

  class Dup2 : public BaseInstruction{
    public:    
      Dup2(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };

  class Dup2X1 : public BaseInstruction{
    public:    
      Dup2X1(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };

  class Dup2X2 : public BaseInstruction{
    public:    
      Dup2X2(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      string toString();
      int execute(Frame *frame);
  };
  
}

#endif
