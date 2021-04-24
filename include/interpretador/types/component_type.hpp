#ifndef __COMPONENT_TYPE_H__
#define __COMPONENT_TYPE_H__

#include <vector>
#include <cstdint>
#include <string>
typedef enum{
  Long, Double, Byte, Short, Boolean, Char, Int, Float, ReturnAdress, Null,   // Tipos basicos 
  Reference,       // Tipos de referencia
  JVMArray, JVMCLASS, JVMOBJ, JVMFIELD, JVMINTERFACE, JVMString, JVMMethodHandle                // Tipos complexos
} JVMType;

using namespace std;

class ComponentType{
  protected:
    int heap_reference;
  public:
    JVMType type;

    ComponentType(JVMType component_type);

    static ComponentType* getDefaultValue(JVMType);
    static JVMType getTypeFromDescriptor(string descriptor);

    void setReference(int);
    int getReference();
    virtual void print();
    virtual string toString();
};

#endif
