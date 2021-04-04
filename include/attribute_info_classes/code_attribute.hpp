#ifndef __ATTR_CODE_ATTR_H__
#define __ATTR_CODE_ATTR_H__
namespace Attribute{
  class CodeAttribute;
}

#include "../attribute_info.hpp"

#include "./code_attribute_classes/instruction.hpp"
#include "./code_attribute_classes/exception_table.hpp"

namespace Attribute{
  class CodeAttribute : public AttributeInfo{
    private:
      uint16_t max_stack;
      uint16_t max_locals;

      vector<Instructions::BaseInstruction*> code;

      uint16_t exception_table_length;
      vector<CodeException*> exception_table;

      uint16_t attributes_count;
      vector<AttributeInfo*> attributes;

      void loadInstructions();
      void loadExceptioTable();
    public:

      uint32_t code_length;
      CodeAttribute(AttrInitialValue initial_value);
      ~CodeAttribute();

      Instructions::BaseInstruction* getInstructionByOpCode(int opcode);

      uint16_t number_of_instructions;
      void printInfo(int n_tabs);
  };
}
#endif
