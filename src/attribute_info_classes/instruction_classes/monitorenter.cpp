#include "../../../include/attribute_info_classes/instruction_classes/monitorenter.hpp"
using namespace Instructions;


MonitorEnter::MonitorEnter(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){   
}

string MonitorEnter::toString(){
  return "monitorenter";
}
