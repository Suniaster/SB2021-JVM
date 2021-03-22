#ifndef __INSTRUCTION_LOOKUPSWITCH_H__
#define __INSTRUCTION_LOOKUPSWITCH_H__

#include <cstdint>
#include "../code_attribute_classes/instruction.hpp"

namespace Instructions{
  class LookupSwitch : public BaseInstruction{
      int32_t default_bytes, n_pairs;
      vector<int32_t> offsets;
      vector<int32_t> matchs;
    public:    
      LookupSwitch(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint32_t pc);
      void print(int);
  };
}

#endif
