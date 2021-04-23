#ifndef __JVM_OBJ_H__
#define __JVM_OBJ_H__

#include "./jvm_class.hpp"

using namespace std;

class JVMObject : public JVMClass{
  private:

  public:

    JVMObject(string class_name);

    void initializeFields();
};


#endif
