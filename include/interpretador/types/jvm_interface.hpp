#ifndef __JVM_INTERFACE_H__
#define __JVM_INTERFACE_H__

#include "./jvm_field.hpp"
#include "./primitive_type.hpp"
#include "../../class_file.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class JVMInterface : public ComponentType{
  private:
    string interface_name;
    vector<JVMField*> fields;
    ClassFile* class_file;
  public:

    // Vetor com pares de <stringConstante, referencia no heap>
    vector<pair<string, uint64_t>> constant_strings;
    JVMInterface(string interface_name);
    
    void setClassFile(ClassFile*);
    void addField(JVMField*);

    JVMField* getField(string field_name);
    PrimitiveType getConstant(int index);
    string toString();
};


#endif
