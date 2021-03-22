#include "../../../include/attribute_info_classes/instruction_classes/monitorexit.hpp"
using namespace Instructions;


MonitorExit::MonitorExit(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string MonitorExit::toString(){
  return "monitorexit";
}
