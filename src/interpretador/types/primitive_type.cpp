#include "../../../include/interpretador/types/primitive_type.hpp"
#include <iostream>
#include <sstream>
#include <cwchar>

void GetUnicodeChar(unsigned int code, char chars[5]) {
    if (code <= 0x7F) {
        chars[0] = (code & 0x7F); chars[1] = '\0';
    } else if (code <= 0x7FF) {
        // one continuation byte
        chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[0] = 0xC0 | (code & 0x1F); chars[2] = '\0';
    } else if (code <= 0xFFFF) {
        // two continuation bytes
        chars[2] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[0] = 0xE0 | (code & 0xF); chars[3] = '\0';
    } else if (code <= 0x10FFFF) {
        // three continuation bytes
        chars[3] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[2] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
        chars[0] = 0xF0 | (code & 0x7); chars[4] = '\0';
    } else {
        // unicode replacement character
        chars[2] = 0xEF; chars[1] = 0xBF; chars[0] = 0xBD;
        chars[3] = '\0';
    }
}

PrimitiveType::PrimitiveType(uint64_t x, JVMType type):ElementType(type){
  this->data =x;
};

void PrimitiveType::print(){
    std::cout << "<" << this->toString() << ", " << this->type << ">" << endl;
}

string PrimitiveType::toString(){
  stringstream paramString;
  if(this->type == Double){
    paramString << to_string(*(double*)&this->data);
  }
  else if(this->type == Float){
    paramString << to_string(*(float*)&this->data);
  }
  else if(this->type == Int){
    paramString << to_string(*(int*)&this->data);
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
    uint16_t x ;
    x = (uint16_t)this->data;
    char chars[5];
    GetUnicodeChar(x, chars);
    paramString << chars ;
  }
  else if(this->type == Boolean){
    if(this->data) paramString << "true";
    else paramString << "false";
  }
  else paramString << this->data;

  return paramString.str();
}