#ifndef __ARRAY_TYPE_H__
#define __ARRAY_TYPE_H__

#include "./component_type.hpp"
#include "./primitive_type.hpp"

#include <vector>
#include <cstdint>

using namespace std;

class ArrayType : public ComponentType{
  private:
    vector<ComponentType*> data;
    JVMType content_type;
    int max_length;
  public:

  ArrayType(JVMType x);

  void insert(ComponentType*);
  void print();

  void setIndexAsPrimitiveType(int index, uint64_t value, JVMType type);
  ComponentType* getIndex(int i);
  pair<uint64_t,JVMType> getIndexAsAsPrimitiveType(int index);

  int getIndexReference(int index);
};

#endif
