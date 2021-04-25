#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>
#include <sstream>

PrimitiveType::PrimitiveType(uint64_t x, JVMType type):ElementType(type){
  this->data =x;
};

void PrimitiveType::print(){
    std::cout << "<" << this->toString() << ", " << this->type << ">" << endl;
}

string PrimitiveType::toString(){
  stringstream paramString;
  if(this->type == Double){
      int64_t value = (int64_t)this->data;
    paramString << to_string((double)value);
  }
  else if(this->type == Float){
      int64_t value = (int64_t)this->data;
      double temp_double = (double)value;
      float float_value = (float)temp_double;
    paramString << to_string(float_value);
  }
  else if(this->type == Int){
    paramString << to_string((int)this->data);
  }
  else if(this->type == Long){
    paramString << to_string(*(int64_t*)&this->data);
  }
  else if(this->type == Byte){
    paramString << to_string(*(int8_t*)&this->data);
  }
  else if(this->type == Short){
    paramString << to_string(*(int16_t*)&this->data);
  }
  else if(this->type == Char){
    paramString << *(char*)&this->data;
  }
  else if(this->type == Boolean){
    if(this->data) paramString << "true";
    else paramString << "false";
  }
  else paramString << this->data;

  return paramString.str();
}