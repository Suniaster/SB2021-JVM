#ifndef __INSTRUCTION_LCD_H__
#define __INSTRUCTION_LCD_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class Lcd : public BaseInstruction{
    private:
      uint8_t index;
    public:    
      Lcd(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      void print();
      uint8_t readOperands();
  };
}

#endif
