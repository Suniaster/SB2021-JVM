#include "../../../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

#include "../../../include/attribute_info_classes/instruction_classes/_include_all.hpp"
#include <sstream>
using namespace Instructions;

BaseInstruction::BaseInstruction(Attribute::CodeAttribute* code_attr, uint8_t opcode){
  this->code_attr = code_attr;
  this->opcode = opcode;
}

int BaseInstruction::execute(Frame* frame){
  this->print();
  return frame->local_pc++;
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

void BaseInstruction::print(int n_tabs){
  this->print();
}

string BaseInstruction::hexToString(int param){
  stringstream paramString;
  paramString << hex << param;
  return paramString.str();
}

string BaseInstruction::intToString(int param){
  stringstream paramString;
  paramString << param;
  return paramString.str();
}

string BaseInstruction::tabs(int n_tabs){
  string str= "";
  while(n_tabs--)str+= "\t";
  return str;
}


string BaseInstruction::intToSignedString(int32_t param){
  string signalStr = "+";
  if(param < 0){
    param *=1;
    signalStr = "-";
  }

  stringstream paramString;
  paramString << param;

  return signalStr + paramString.str();
} 

string BaseInstruction::createStringWithCPRef(string name, uint16_t index){
  return name +" #" + this->intToString(index) + 
  " <" + this->code_attr->class_file->getConstantPoolEntry(index)->toString()
  + ">";
}

string BaseInstruction::getTypePrefix(uint8_t type){
  switch (type){
    case I_TYPE :
      return "i";
    case F_TYPE:
      return "f";
    case L_TYPE:
      return "l";
    case D_TYPE:
      return "d";
    case A_TYPE:
      return "a";
    default:
      return "undefinedPrefix";
  }
}

BaseInstruction* BaseInstruction::getInstance(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint32_t pc){

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
  case 0x26 ... 0x29:
    return new Dload(code_attr, opcode);
  case 0x2a ... 0x2d:
    return new Aload(code_attr, opcode);
  case 0x2e:
    return new Iaload(code_attr, opcode);
  case 0x2f:
    return new Laload(code_attr, opcode);
  case 0x30:
    return new Faload(code_attr, opcode);  
  case 0x31:
    return new Baload(code_attr, opcode);  
  case 0x32:
    return new Aaload(code_attr, opcode);  
  case 0x33:
    return new Baload(code_attr, opcode);   
  case 0x34:
    return new Caload(code_attr, opcode);
  case 0x35:
    return new Saload(code_attr, opcode);
  case 0x36:
    return new Istore(code_attr, opcode);
  case 0x37:
    return new Lstore(code_attr, opcode);
  case 0x38:
    return new Fstore(code_attr, opcode);
  case 0x39:
    return new Dstore(code_attr, opcode);
  case 0x3a:
    return new Astore(code_attr, opcode);
  case 0x3b ... 0x3e:
    return new Istore(code_attr, opcode);
  case 0x3f ... 0x42:
    return new Lstore(code_attr, opcode);
  case 0x43 ... 0x46:
    return new Fstore(code_attr, opcode);
  case 0x47 ... 0x4a:
    return new Dstore(code_attr, opcode);
  case 0x4b ... 0x4e:
    return new Astore(code_attr, opcode);
  case 0x4f:
    return new Iastore(code_attr, opcode);
  case 0x50:
    return new Lastore(code_attr, opcode);
  case 0x51:
    return new Fastore(code_attr, opcode);  
  case 0x52:
    return new Bastore(code_attr, opcode);  
  case 0x53:
    return new Aastore(code_attr, opcode);  
  case 0x54:
    return new Bastore(code_attr, opcode);   
  case 0x55:
    return new Castore(code_attr, opcode);
  case 0x56:
    return new Sastore(code_attr, opcode);
  case 0x57:
    return new Pop(code_attr, opcode);
  case 0x58:
    return new Pop2(code_attr, opcode);
  case 0x59:
    return new Dup(code_attr, opcode);
  case 0x5a:
    return new DupX1(code_attr, opcode);
  case 0x5b:
    return new DupX2(code_attr, opcode);
  case 0x5c:
    return new Dup2(code_attr, opcode);
  case 0x5d:
    return new Dup2X1(code_attr, opcode);
  case 0x5e:
    return new Dup2X2(code_attr, opcode);
  case 0x5f:
    return new Swap(code_attr, opcode);
  case 0x60 ... 0x63:
    return new Add(code_attr, opcode);
  case 0x64 ... 0x67:
    return new Sub(code_attr, opcode);
  case 0x68 ... 0x6b:
    return new Mul(code_attr, opcode);
  case 0x6c ... 0x6f:
    return new Div(code_attr, opcode);
  case 0x70 ... 0x73:
    return new Rem(code_attr, opcode);
  case 0x74 ... 0x77:
    return new Neg(code_attr, opcode);
  case 0x78 ... 0x79:
    return new Shl(code_attr, opcode);
  case 0x7a ... 0x7b:
    return new Shr(code_attr, opcode);
  case 0x7c ... 0x7d:
    return new Ushr(code_attr, opcode);
  case 0x7e ... 0x7f:
    return new And(code_attr, opcode);
  case 0x80 ... 0x81:
    return new Or(code_attr, opcode);
  case 0x82 ... 0x83:
    return new Xor(code_attr, opcode);
  case 0x84:
    return new Inc(code_attr, opcode);
  case 0x85 ... 0x93:
    return new TypeConversion(code_attr, opcode);
  case 0x94:
    return new Lcmp(code_attr, opcode);
  case 0x95 ... 0x96:
    return new Fcmp(code_attr, opcode);
  case 0x97 ... 0x98:
    return new Dcmp(code_attr, opcode);
  case 0x99 ... 0x9e:
    return new If(code_attr, opcode);
  case 0x9f ... 0xa4:
    return new If_icmp(code_attr, opcode);
  case 0xa7:
    return new Goto(code_attr, opcode);
  case 0xa8:
    return new Jsr(code_attr, opcode);
  case 0xa9:
    return new Ret(code_attr, opcode);
  case 0xaa:
    return new TableSwitch(code_attr, opcode, pc);
  case 0xab:
    return new LookupSwitch(code_attr, opcode, pc);
  case 0xac ... 0xb0:
    return new _Return(code_attr, opcode);
  case 0xb1:
    return new Return(code_attr, opcode);
  case 0xb2:
    return new GetStatic(code_attr, opcode);  
  case 0xb3:
    return new PutStatic(code_attr, opcode);  
  case 0xb4:
    return new GetField(code_attr, opcode);
  case 0xb5:
    return new PutField(code_attr, opcode);
  case 0xb6:
    return new InvokeVirtual(code_attr, opcode);
  case 0xb7:
    return new InvokeSpecial(code_attr, opcode);
  case 0xb8:
    return new InvokeStatic(code_attr, opcode);
  case 0xb9: // nao foi testado
    return new InvokeInterface(code_attr, opcode);
  case 0xbb:
    return new New(code_attr, opcode);
  case 0xbc:
    return new NewArray(code_attr, opcode);
  case 0xbd:
    return new ANewArray(code_attr, opcode);
  case 0xbe:
    return new ArrayLength(code_attr, opcode);
  case 0xbf:
    return new Athrow(code_attr, opcode);
  case 0xc0:
    return new CheckCast(code_attr, opcode);
  case 0xc1:
    return new Instanceof(code_attr, opcode);
  case 0xc2:
    return new MonitorEnter(code_attr, opcode);
  case 0xc3:
    return new MonitorExit(code_attr, opcode);
  case 0xc4: // nao foi testado
    return new Wide(code_attr, opcode);
  case 0xc5: // nao foi testado
    return new MultiANewArray(code_attr, opcode);
  case 0xc6: // nao foi testado
    return new Ifnull(code_attr, opcode);
  case 0xc7: // nao foi testado
    return new Ifnonnull(code_attr, opcode);
  case 0xc8: // nao foi testado
    return new Goto_W(code_attr, opcode);
  case 0xc9: // nao foi testado
    return new Jsr_W(code_attr, opcode);
  }

  return new BaseInstruction(code_attr, opcode);
}