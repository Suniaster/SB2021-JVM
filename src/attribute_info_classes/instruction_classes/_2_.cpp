#include "../../../include/attribute_info_classes/instruction_classes/_2_.hpp"
using namespace Instructions;


TypeConversion::TypeConversion(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  this->type = this->opcode - this->BASE_OPCODE;  
}

string TypeConversion::toString(){
  return this->types[this->type];
}

int TypeConversion::execute(Frame* frame){

  uint64_t value1 = frame -> operand_stack.pop().first;

  switch(this->type){
    case 0:{           //i2l
      int v1 = (int)value1;
      int64_t result = (int64_t)v1;
      frame -> operand_stack.push(result, Long);
      break;}
    case 1: {          //i2f
      int v1 = (int)value1;
      float result = *(float*)&v1;
      frame -> operand_stack.push(result, Float);
      break;}
    case 2:  {         //i2d
      int v1 = (int)value1;
      double result = *(double*)&v1;
      frame -> operand_stack.push(result, Double);
      break;}
    case 3:     {      //l2i
      int64_t v1 = (int64_t)value1;
      int result = (int)v1;
      frame -> operand_stack.push(result, Int);
      break;}
    case 4:{           //l2f
      int64_t v1 = (int64_t)value1;
      float result = *(float*)&v1;
      frame -> operand_stack.push(result, Float);
      break;}
    case 5:    {       //l2d
      int64_t v1 = (int64_t)value1;
      double result = *(double*)&v1;
      frame -> operand_stack.push(result, Double);
      break;}
    case 6: {          //f2i
      float v1 = *(float*)&value1;
      int result = (int)v1;
      frame -> operand_stack.push(result, Int);
      break;}
    case 7: {          //f2l
      float v1 = *(float*)&value1;
      int64_t result = (int64_t)v1;
      frame -> operand_stack.push(result, Long);
      break;}
    case 8: {          //f2d
      float v1 = *(float*)&value1;
      double result = (double)v1;
      frame -> operand_stack.push(result, Double);
      break;}
    case 9:   {        //d2i
      double v1 = *(double*)&value1;
      int result = (int)v1;
      frame -> operand_stack.push(result, Int);
      break;}
    case 10:{           //d2l
      double v1 = *(double*)&value1;
      int64_t result = (int64_t)v1;
      frame -> operand_stack.push(result, Long);
      break;}
    case 11:  {         //d2f
      double v1 = *(double*)&value1;
      float result = (float)v1;
      frame -> operand_stack.push(result, Float);
      break;}
    case 12:{           //i2b
      int v1 = (int)value1;
      int8_t result = (int8_t)v1;
      frame -> operand_stack.push(result, Byte);
      break;}
    case 13:  {         //i2c
      int v1 = (int)value1;
      uint8_t result = (uint8_t)v1;
      frame -> operand_stack.push(result, Char);
      break;}
    case 14:{           //i2s
      int v1 = (int)value1;
      int16_t result = (int16_t)v1;
      frame -> operand_stack.push(result, Short);
      break;}
  }

  return frame -> local_pc++;
}