#include "../../../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

#include "../../../include/attribute_info_classes/instruction_classes/_include_all.hpp"
#include <sstream>
using namespace Instructions;

BaseInstruction::BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode){
  this->code_attr = code_attr;
  this->opcode = opcode;
}

string BaseInstruction::toString(){
  string baseName  = "Instrucao Base (0x";
  baseName += this->hexToString(this->opcode);
  baseName += ")";
  return baseName ;
}

void BaseInstruction::print(){
  cout << dec << this->toString() << endl;
}

string BaseInstruction::hexToString(int param){
  stringstream paramString;
  paramString << hex << param;
  return paramString.str();
}

BaseInstruction* BaseInstruction::getInstance(Attribute::CodeAttribute* code_attr, uint8_t opcode){

  switch (opcode){
  case 0x0:
    return new Nop(code_attr, opcode);
  case 0x2 ... 0x8:
    return new Iconst(code_attr, opcode);
  case 0x9 ... 0xa:
    return new Lconst(code_attr, opcode);
  case 0xb ... 0xd:
    return new Fconst(code_attr, opcode);
  case 0xe ... 0xf:
    return new Dconst(code_attr, opcode);
  case 0x10:
    return new Bipush(code_attr, opcode);
  case 0x11:
    return new Sipush(code_attr, opcode);
  case 0x12:
    return new Ldc(code_attr, opcode);
  case 0x13:
    return new LdcW(code_attr, opcode);
  case 0x14:
    return new Ldc2W(code_attr, opcode);
  case 0x15:
    return new Iload(code_attr, opcode);
  case 0x16:
    return new Lload(code_attr, opcode);
  case 0x17:
    return new Fload(code_attr, opcode);
  case 0x18:
    return new Dload(code_attr, opcode);
  case 0x19:
    return new Aload(code_attr, opcode);
  case 0x1a ... 0x1d:
    return new Iload(code_attr, opcode);
  case 0x1e ... 0x22:
    return new Lload(code_attr, opcode);
  case 0x23 ... 0x25:
    return new Fload(code_attr, opcode);
  case 0x26 ... 0x28:
    return new Dload(code_attr, opcode);
  case 0x29 ... 0x2d:
    return new Aload(code_attr, opcode);
  case 0xb2:
    return new GetStatic(code_attr, opcode);  
  case 0xbb:
    return new New(code_attr, opcode);
  case 0x59:
    return new Dup(code_attr, opcode);
  case 0xb7:
    return new InvokeSpecial(code_attr, opcode);
  case 0xb6:
    return new InvokeVirtual(code_attr, opcode);
  case 0xb5:
    return new PutField(code_attr, opcode);
  case 0xb1:
    return new Return(code_attr, opcode);
  case 0xb4:
    return new GetField(code_attr, opcode);
  case 0xbf:
    return new Athrow(code_attr, opcode);
  }

  if(opcode >= 0x4b && opcode <= 0x4e){
    return new Astore(code_attr, opcode);
  }

  return new BaseInstruction(code_attr, opcode);
}