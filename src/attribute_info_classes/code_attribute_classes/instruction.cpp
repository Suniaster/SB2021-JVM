#include "../../../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

#include "../../../include/attribute_info_classes/instruction_classes/getstatic.hpp"
#include "../../../include/attribute_info_classes/instruction_classes/lcd.hpp"

using namespace Instructions;

BaseInstruction::BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode){
  this->code_attr = code_attr;
  this->opcode = opcode;
}

void BaseInstruction::print(){
  cout << "\t\tInstrucao Base (0x" << hex << (int)this->opcode << ")" << endl;
}

BaseInstruction* BaseInstruction::getInstance(Attribute::CodeAttribute* code_attr, uint8_t opcode){

  switch (opcode){
  case 0x12:
    return new Lcd(code_attr, opcode);
  case 0xb2:
    return new GetStatic(code_attr, opcode);  
  default:
    return new BaseInstruction(code_attr, opcode);
  }
}