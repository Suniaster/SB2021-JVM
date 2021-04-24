//
// Created by gabriel on 23/04/2021.
//

#include "../../include/interpretador/interface_loader.hpp"
#include "../../include/interpretador/types/jvm_interface.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"
#include "../../include/interpretador/execution_engine.hpp"

void InterfaceLoader::linkInterface(string interface_name, MethodArea* method_area){
    Heap* heap = Heap::getInstance();
    JVMInterface* linking_interface = new JVMInterface(interface_name);

    ClassFile* interface_file = method_area->getClassFile(interface_name);
    linking_interface->setClassFile(interface_file);


    // Link fields
    for(uint16_t i=0;i<interface_file->fields.size();i+=1){
        FieldInfo* field = interface_file->fields[i];

        JVMField* newFieldAlocated = new JVMField(field);
        heap->storeComponent(newFieldAlocated);
        linking_interface->addField(newFieldAlocated);

    }

    interface_file->heap_ref = heap->storeComponent(linking_interface);

    interface_file->state = LINKED;
}

void InterfaceLoader::initializeInterface(string interface_name, MethodArea* method_area){
    ClassFile* interface_file = method_area->getClassFile(interface_name);

    Thread* main_thread =  ExecutionEngine::getInstance()->main_thread;


    interface_file->state = INITIALIZED;
}

bool InterfaceLoader::interfaceIs(ClassFileState state, string interface_name, MethodArea* method_area){
    ClassFile* interface_file = method_area->getClassFile(interface_name);
    return interface_file->state >= state;
}

bool InterfaceLoader::interfaceIsNot(ClassFileState state, string interface_name, MethodArea* method_area){
    return !InterfaceLoader::interfaceIs(state, interface_name, method_area);
}

int InterfaceLoader::resolveInterface(string interface_name, MethodArea* method_area){
    if(InterfaceLoader::interfaceIsNot(LOADED, interface_name, method_area)){
        throw runtime_error("LoadError: "+interface_name+" is not loaded");
    }

    if(InterfaceLoader::interfaceIsNot(LINKED, interface_name, method_area)){
        InterfaceLoader::linkInterface(interface_name, method_area);
    }

    if(InterfaceLoader::interfaceIsNot(INITIALIZED, interface_name, method_area)){
        InterfaceLoader::initializeInterface(interface_name, method_area);
    }

    // TODO: Resolver super-interfacees

    ClassFile* interface_file = method_area->getClassFile(interface_name);
    return interface_file->heap_ref;
}