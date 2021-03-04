#include "../../../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

using namespace Instructions;

BaseInstruction::BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode){
  this->code_attr = code_attr;
  this->opcode = opcode;
}

void BaseInstruction::print(){
  cout << "Instrucao Base (0x" << hex << (int)this->opcode << ")" << endl;
}

uint8_t BaseInstruction::readOperands(){
  // Instrucao base assume que nao ha operando a serem lidos
  return 0;
}

BaseInstruction* BaseInstruction::getInstance(Attribute::CodeAttribute* code_attr, uint8_t opcode){
  //TODO: Fazer swithcase dependendo do opcode
  return new BaseInstruction(code_attr, opcode);
}