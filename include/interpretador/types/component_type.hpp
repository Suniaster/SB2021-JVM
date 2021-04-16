#ifndef __COMPONENT_TYPE_H__
#define __COMPONENT_TYPE_H__

#include <vector>
#include <cstdint>
typedef enum{
  Long, Double, Byte, Short, Boolean, Char, Int, Float, ReturnAdress,   // Tipos basicos 
  Reference, ArrayReference, ObjectReference, InterfaceReference,       // Tipos de referencia
  JVMArray                                                              // Tipos complexos
} JVMType;

using namespace std;

class ComponentType{
  protected:
    int heap_reference;
  public:
    JVMType type;

    ComponentType(JVMType component_type);
    void setReference(int);
    int getReference();
    virtual void print();
};

#endif
