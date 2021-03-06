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

  public:
    uint8_t tag;
    CpInfo(ClassFile *class_file);
    virtual ~CpInfo() { };

    virtual void setInfo() = 0;
    virtual void printInfo() = 0;
    virtual string toString();

    virtual uint64_t getValue();

    static CpInfo* returnUnusableSpace(ClassFile* class_file);
    static CpInfo* getInstance(uint8_t tag, ClassFile* class_file);
    static CpInfo* getUtf8(vector<CpInfo*> constant_pool, int index);
};


#endif
