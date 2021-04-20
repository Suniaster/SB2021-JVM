#include "../../../include/attribute_info_classes/instruction_classes/dup.hpp"
using namespace Instructions;

Dup::Dup(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode)
{
}

string Dup::toString()
{
  return "dup";
}

int Dup::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value = frame->operand_stack.readPosition(0);

  frame->operand_stack.push(value.first, value.second);

  frame->local_pc += 1;
  return frame->local_pc;
};

DupX1::DupX1(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {}
string DupX1::toString()
{
  return "dup_x1";
}

int DupX1::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value1 = frame->operand_stack.readPosition(0);

  frame->operand_stack.insert(2, value1.first, value1.second);

  frame->local_pc += 1;
  return frame->local_pc;
};

DupX2::DupX2(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {}
string DupX2::toString()
{
  return "dup_x2";
}

int DupX2::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value1 = frame->operand_stack.readPosition(0);
  pair<uint64_t, JVMType> value2 = frame->operand_stack.readPosition(1);

  if (value2.second == Long || value2.second == Double)
  {
    frame->operand_stack.insert(2, value1.first, value1.second);
  }
  else
  {
    frame->operand_stack.insert(3, value1.first, value1.second);
  }

  frame->local_pc += 1;
  return frame->local_pc;
}

Dup2::Dup2(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {}
string Dup2::toString()
{
  return "dup2";
}

int Dup2::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value1 = frame->operand_stack.readPosition(0);
  pair<uint64_t, JVMType> value2 = frame->operand_stack.readPosition(1);

  if (value1.second == Long || value1.second == Double)
    frame->operand_stack.push(value1.first, value1.second);
  else
  {
    frame->operand_stack.push(value2.first, value2.second);
    frame->operand_stack.push(value1.first, value1.second);
  }

  frame->local_pc += 1;
  return frame->local_pc;
}

Dup2X1::Dup2X1(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {}
string Dup2X1::toString()
{
  return "dup2_x1";
}

int Dup2X1::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value1 = frame->operand_stack.readPosition(0);
  pair<uint64_t, JVMType> value2 = frame->operand_stack.readPosition(1);

  if (value1.second == Long || value1.second == Double)
    frame->operand_stack.insert(2, value1.first, value1.second);
  else
  {
    frame->operand_stack.insert(3, value1.first, value1.second);
    frame->operand_stack.insert(4, value2.first, value2.second);
  }

  frame->local_pc += 1;
  return frame->local_pc;
}

Dup2X2::Dup2X2(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode) {}
string Dup2X2::toString()
{
  return "dup2_x2";
}

int Dup2X2::execute(Frame *frame)
{
  pair<uint64_t, JVMType> value1 = frame->operand_stack.readPosition(0);
  pair<uint64_t, JVMType> value2 = frame->operand_stack.readPosition(1);
  pair<uint64_t, JVMType> value3 = frame->operand_stack.readPosition(2);

  if (value1.second == Long || value1.second == Double)
  {
    if (value2.second == Long || value2.second == Double)
      frame->operand_stack.insert(2, value1.first, value1.second);
    else 
      frame->operand_stack.insert(3, value1.first, value1.second);
  }
  else 
  {
    if (value3.second == Long || value3.second == Double) {
      frame->operand_stack.insert(3, value1.first, value1.second);
      frame->operand_stack.insert(4, value2.first, value2.second);
    }
    else {
      frame->operand_stack.insert(4, value1.first, value1.second);
      frame->operand_stack.insert(5, value2.first, value2.second);
    }
  }

  frame->local_pc += 1;
  return frame->local_pc;
}