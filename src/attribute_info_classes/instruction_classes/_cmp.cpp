#include "../../../include/attribute_info_classes/instruction_classes/_cmp.hpp"
using namespace Instructions;

Lcmp::Lcmp(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {
}

string Lcmp::toString() {
  return "lcmp";
}

int Lcmp::execute(Frame *frame) {
  int64_t value2 = frame->operand_stack.pop().first;
  int64_t value1 = frame->operand_stack.pop().first;

  int64_t lvalue1 = (int64_t)value1;
  int64_t lvalue2 = (int64_t)value2;
  int32_t result;

  if (lvalue1 > lvalue2) {
    result = (int32_t)1;
    frame->operand_stack.push(result, Int);
  }
  else if (lvalue1 == lvalue2) {
    result = (int32_t)0;
    frame->operand_stack.push(result, Int);
  }
  else {
    result = (int32_t)-1;
    frame->operand_stack.push(result, Int);
  }

  return frame -> local_pc++;
}

Fcmp::Fcmp(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {
      this->type = this->opcode - this->BASE_OPCODE;  
}

string Fcmp::toString() {
  switch(this->type) {
    case 0:
      return "fcmpl";
      break;
    case 1:
      return "fcmpg";
      break;
  }
}

int Fcmp::execute(Frame *frame) {
  float value2 = frame->operand_stack.pop().first;
  float value1 = frame->operand_stack.pop().first;

  float fvalue1 = *(float *)&value1;
  float fvalue2 = *(float *)&value2;
  int32_t result;

  if (fvalue1 > fvalue2) {
    result = (int32_t)1;
    frame->operand_stack.push(result, Int);
  }
  else if (fvalue1 == fvalue2) {
    result = (int32_t)0;
    frame->operand_stack.push(result, Int);
  }
  else if (fvalue1 < fvalue2) {
    result = (int32_t)-1;
    frame->operand_stack.push(result, Int);
  }
  else {
    switch(this->type) {
      case 0:
        result = (int32_t)-1;
        frame->operand_stack.push(result, Int);
        break;
      case 1:
        result = (int32_t)1;
        frame->operand_stack.push(result, Int);
        break;
    }
  }

  return frame -> local_pc++;
}

Dcmp::Dcmp(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {
      this->type = this->opcode - this->BASE_OPCODE;  
}

string Dcmp::toString() {
  switch(this->type) {
    case 0:
      return "dcmpl";
      break;
    case 1:
      return "dcmpg";
      break;
  }
}

int Dcmp::execute(Frame *frame) {
  double value2 = frame->operand_stack.pop().first;
  double value1 = frame->operand_stack.pop().first;

  double dvalue1 = *(double *)&value1;
  double dvalue2 = *(double *)&value2;
  int32_t result;

  if (dvalue1 > dvalue2) {
    result = (int32_t)1;
    frame->operand_stack.push(result, Int);
  }
  else if (dvalue1 == dvalue2) {
    result = (int32_t)0;
    frame->operand_stack.push(result, Int);
  }
  else if (dvalue1 < dvalue2) {
    result = (int32_t)-1;
    frame->operand_stack.push(result, Int);
  }
  else {
    switch(this->type) {
      case 0:
        result = (int32_t)-1;
        frame->operand_stack.push(result, Int);
        break;
      case 1:
        result = (int32_t)1;
        frame->operand_stack.push(result, Int);
        break;
    }
  }

  return frame -> local_pc++;
}
