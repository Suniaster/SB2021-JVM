#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
namespace Instructions{
  class BaseInstruction;
}

#include <cstdint>
#include "../code_attribute.hpp"
#include <sstream>

#define I_TYPE 0x0
#define L_TYPE 0x1
#define F_TYPE 0x2
#define D_TYPE 0x3
#define A_TYPE 0x4

namespace Instructions{
  class BaseInstruction{
    protected:
      uint8_t opcode;
      Attribute::CodeAttribute* code_attr;
      string hexToString(int);
      string intToString(int);
      string intToSignedString(int);
      string createStringWithCPRef(string name, uint16_t index);
      string tabs(int);
    public:    
      uint16_t pc;
      BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      virtual ~BaseInstruction() {};

      virtual void print();
      virtual void print(int);
      virtual string toString();
      static string getTypePrefix(uint8_t type);
      static BaseInstruction* getInstance(Attribute::CodeAttribute* code_attr,uint8_t opcode, uint32_t pc);
  };
}

#endif
