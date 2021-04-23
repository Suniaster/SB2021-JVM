#ifndef __JVM_CLASS_H__
#define __JVM_CLASS_H__

#include "./jvm_field.hpp"
#include "./primitive_type.hpp"
#include "../../class_file.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class JVMClass : public ComponentType{
  protected:
    string class_name;
    vector<JVMField*> fields;
  public:
    ClassFile* class_file;

    // Vetor com pares de <stringConstante, referencia no heap>
    vector<pair<string, uint64_t>> constant_strings;
    JVMClass(string class_name);
    
    void setClassFile(ClassFile*);
    void addField(JVMField*);

    JVMField* getField(string field_name);
    PrimitiveType getConstant(int index);
    
    virtual void initializeFields();
    virtual string toString();
};


#endif
