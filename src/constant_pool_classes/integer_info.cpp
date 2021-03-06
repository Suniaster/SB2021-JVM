#include "../../include/constant_pool_classes/integer_info.hpp"



CP::IntegerInfo::IntegerInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 3;
}

void CP::IntegerInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->bytes);
}

void CP::IntegerInfo::printInfo(){

  cout << "\tInteger: Bytes " << hex <<this->bytes << endl;
  cout << "\tInteger: Value " << dec << this->returnInteger() << endl;


}

int CP::IntegerInfo::returnInteger(){
    return (int) this->bytes;
}
string CP::IntegerInfo::toString(){
 return std::to_string(this->returnInteger());
}
