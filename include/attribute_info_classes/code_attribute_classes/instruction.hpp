#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
namespace Instructions{
  class BaseInstruction;
}

#include <cstdint>
#include "../code_attribute.hpp"
#include "../../interpretador/frame.hpp"
#include <sstream>
#include "../../constant_pool_classes/method_ref_info.hpp"
#include "../../constant_pool_classes/class_info.hpp"
#include "../../constant_pool_classes/utf8_info.hpp"
#include "../../constant_pool_classes/string_info.hpp"
#include "../../constant_pool_classes/name_and_type_info.hpp"
#include "../../constant_pool_classes/field_ref_info.hpp"
#include "../../constant_pool_classes/interface_method_ref_info.hpp"
#include "../../constant_pool_classes/integer_info.hpp"
#include "../../constant_pool_classes/float_info.hpp"
#include "../../constant_pool_classes/long_info.hpp"
#include "../../constant_pool_classes/double_info.hpp"
#include "../../constant_pool_classes/method_type_info.hpp"
#include "../../constant_pool_classes/invoke_dynamic_info.hpp"
#include "../../constant_pool_classes/method_handle_info.hpp"
#include "../../constant_pool_classes/unused_info.hpp"
#include "../../interpretador/types/string_type.hpp"
#include "../../interpretador/types/method_handle_type.hpp"


#define I_TYPE 0x0
#define L_TYPE 0x1
#define F_TYPE 0x2
#define D_TYPE 0x3
#define A_TYPE 0x4

namespace Instructions{
  class BaseInstruction{
    protected:
      Attribute::CodeAttribute* code_attr;
      string hexToString(int);
      string intToString(int);
      string intToSignedString(int);
      string createStringWithCPRef(string name, uint16_t index);
      string tabs(int);
    public:
      uint8_t opcode;
      uint16_t pc;
      BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode);
      virtual ~BaseInstruction() {};

      virtual void print();
      virtual void print(int);
      virtual string toString();

      virtual int execute(Frame* frame);

      static string getTypePrefix(uint8_t type);
      static BaseInstruction* getInstance(Attribute::CodeAttribute* code_attr,uint8_t opcode, uint32_t pc);
  };
}

#endif
