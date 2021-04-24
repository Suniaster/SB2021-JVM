#include "../../../include/attribute_info_classes/instruction_classes/_const.hpp"
using namespace Instructions;

AconstNull::AconstNull(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

int AconstNull::execute(Frame *frame){
    // JVMType Null = Null;
    frame->operand_stack.push(JVMNULL, Reference);
    return frame->local_pc++;
}

string AconstNull::toString(){
  return "aconst_null";
}

Iconst::Iconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}
int Iconst::execute(Frame *frame){

    switch (this->opcode) {
        case 2:
            frame->operand_stack.push(0xFFFFFFFFFFF, Int);
            break;
        case 3:
            frame->operand_stack.push(0, Int);
            break;
        case 4:
            frame->operand_stack.push(1, Int);
            break;
        case 5:
            frame->operand_stack.push(2, Int);
            break;
        case 6:
            frame->operand_stack.push(3, Int);
            break;
        case 7:
            frame->operand_stack.push(4, Int);
            break;
        case 8:
            frame->operand_stack.push(5, Int);
            break;
        default:
            throw std::runtime_error("wrong opcode Iconst");
    }

    return frame->local_pc++;
}

string Iconst::toString(){
  stringstream opcodeString;
  string className = "iconst_";
  if(this->opcode == 2){
    className += "m1";
  }
  else{
    opcodeString << (int)this->opcode-3;
  }
  return className + opcodeString.str();
}

Lconst::Lconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

int Lconst::execute(Frame *frame) {
    switch (this->opcode) {
        case 0x9:
            frame->operand_stack.push(0, Long);
            break;
        case 0xa:
            frame->operand_stack.push(1, Long);
            break;

        default:
            throw std::runtime_error("wrong opcode Lconst");
    }
    return frame->local_pc++;
}

string Lconst::toString(){
  return "lconst_" + this->intToString(this->opcode - 0x9);
}

Fconst::Fconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

int Fconst::execute(Frame * frame){
    float val;
    switch (this->opcode) {
        case 11:
            val = 0;
            break;
        case 12:
            val = 1;
            break;
        case 13:
            val = 2;
            break;

        default:
            throw std::runtime_error("wrong opcode Iconst");
    }
    // cout << "FCONST" << val << endl;
    frame->operand_stack.push(*(uint64_t*)&val, Float);
    return frame->local_pc++;
}
string Fconst::toString(){
  return "fconst_"+this->intToString(this->opcode - 0xb);
}

Dconst::Dconst(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
}

int Dconst::execute(Frame * frame){
    double val;
    switch (this->opcode) {
        case 14:
            val = 0;
            break;
        case 15:
            val = 1;
            break;
        default:
            throw std::runtime_error("wrong opcode Iconst");
    }
    frame->operand_stack.push(*(uint64_t*)&val, Float);
    return frame->local_pc++;
}
string Dconst::toString(){
  return "dconst_"+this->intToString(this->opcode - 0xe);
}
