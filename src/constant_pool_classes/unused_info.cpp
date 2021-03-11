#include "../../include/constant_pool_classes/unused_info.hpp"


CP::UnusedInfo::UnusedInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 0;
}


void CP::UnusedInfo::setInfo(){

}

void CP::UnusedInfo::printInfo(){
    std::cout << "Unusable Space" << '\n';
}
