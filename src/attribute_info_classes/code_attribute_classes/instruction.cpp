#include "../../../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

using namespace Instructions;

BaseInstruction::BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t bytecode){
  this->code_attr = code_attr;
  this->bytecode = bytecode;
}

void BaseInstruction::print(){
  cout << hex;
  cout << "Instrucao Base (0x" << this->bytecode << ")";
}

void BaseInstruction::readOperands(){
  // Instrucao base assume que nao ha operando a serem lidos
}

BaseInstruction* BaseInstruction::getInstance(Attribute::CodeAttribute* code_attr, uint8_t bytecode){
  //TODO: Fazer swithcase dependendo do bytecode
  return new BaseInstruction(code_attr, bytecode);
}