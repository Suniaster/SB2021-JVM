//
// Created by gabriel on 23/04/2021.
//

#include "../../../include/interpretador/types/jvm_interface.hpp"
#include <iostream>
#include <sstream>

JVMInterface::JVMInterface(string interface_name):ComponentType(JVMINTERFACE){
    this->interface_name = interface_name;
}

void JVMInterface::setClassFile(ClassFile* c){
    this->class_file = c;
}

PrimitiveType JVMInterface::getConstant(int index){

    uint64_t return_data;
    JVMType return_type;


    return PrimitiveType(return_data, return_type);
}

void JVMInterface::addField(JVMField* a){
    this->fields.push_back(a);
}

JVMField* JVMInterface::getField(string field_name){
    for(uint16_t i=0;i< this->fields.size();i++){
        if(this->fields[i]->field_name == field_name){
            return this->fields[i];
        }
    }
    throw std::runtime_error("ResolveFieldError: " + field_name + "not found");
}

string JVMInterface::toString(){
    stringstream paramString;

    paramString << "{ Interface: " << this->class_file->getThisClassName() << " ";
    paramString << "fields(" << this->fields.size() << "){";
    for(uint16_t i=0;i< this->fields.size();i++){
        paramString << this->fields[i]->toString();
        if(i!=  this->fields.size()-1){
            paramString << ", ";
        }
    }
    paramString << "}}";
    return paramString.str();
}