#include "../../include/constant_pool_classes/utf8_info.hpp"



CP::Utf8Info::Utf8Info(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 1;
}

void CP::Utf8Info::setInfo(){
  this->class_file->setAttribute<uint16_t>(2, this->length);
  this->bytes = new uint8_t[this->length];
  for (size_t i = 0; i < this->length; i++) {
      this->class_file->setAttribute<uint8_t>(1, this->bytes[i]);
  }

}

string CP::Utf8Info::returnString(){
    string to_return = "";
    for (size_t i = 0; i < this->length; i++) {
        to_return = to_return + (char) this->bytes[i];
    }
    return to_return;
}

void CP::Utf8Info::printInfo(){
  cout << "Utf8Info: Length " << this->length << endl;

  cout << "Utf8Info: String " << this->returnString() << endl;

}
