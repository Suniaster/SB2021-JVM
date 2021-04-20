#ifndef __INSTRUCTION_TABLESWITCH_H__
#define __INSTRUCTION_TABLESWITCH_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class TableSwitch : public BaseInstruction{
      int32_t default_bytes, low_bytes, high_bytes;
      int32_t table_length;
      vector<int32_t> jump_offsets;
      
    public:    
      TableSwitch(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint32_t pc);
      void print(int);
      int execute(Frame *frame);
  };
}

#endif
