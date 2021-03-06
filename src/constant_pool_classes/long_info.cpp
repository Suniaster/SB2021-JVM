#include "../../include/constant_pool_classes/long_info.hpp"



CP::LongInfo::LongInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 5;
}

void CP::LongInfo::setInfo(){
  this->class_file->setAttribute<uint32_t>(4, this->bytes);
}

void CP::LongInfo::printInfo(){
  cout << "Long: B " << this->bytes << endl;

}
