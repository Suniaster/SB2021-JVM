#ifndef __INTERFACE_INFO_H__
#define __INTERFACE_INFO_H__
class InterfaceInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"

using namespace std;

class InterfaceInfo{
private:
    uint16_t interface_info;
    ClassFile *class_file;

public:
    InterfaceInfo(ClassFile *class_file);
    
    void printInfo();
};


#endif