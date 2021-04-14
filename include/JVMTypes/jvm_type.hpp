#ifndef __JVM_TYPE_H__
#define __JVM_TYPE_H__

#include <cstdint>
#include <vector>

using namespace std;

class JVMType {
};

template <typename T>
class JVMType_t : public JVMType {
  public: 
    T data;
};

#endif