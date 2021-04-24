#ifndef __JVM_FIELD_H__
#define __JVM_FIELD_H__

#include "./component_type.hpp"
#include "../../field_info.hpp"
#include <cstdint>
#include <string>

using namespace std;

class JVMField : public ComponentType{
  private:
    ComponentType* data;
    JVMType field_type;
  public:
    FieldInfo* field_info_ref;
    string field_name;

    JVMField(FieldInfo*);

    void setData(ComponentType*);
    ComponentType* getData();
    string toString();
};

#endif
