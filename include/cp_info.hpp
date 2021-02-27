#ifndef __CP_INFO_H__
#define __CP_INFO_H__
class CpInfo;

#include <vector>
#include <string>
#include "./class_file.hpp"

using namespace std;


class CpInfo{
  protected: 
    ClassFile *class_file;
    uint8_t tag;
    
  public:
    CpInfo(ClassFile *class_file);

    virtual void setInfo() = 0;
    virtual void printInfo() = 0;

    static CpInfo* getInstance(uint8_t tag, ClassFile* class_file);
};


#endif
