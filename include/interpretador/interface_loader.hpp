//
// Created by gabriel on 23/04/2021.
//


#ifndef __INTERFACE_LOADER_H__
#define __INTERFACE_LOADER_H__

#include "./types/component_type.hpp"
#include "./types/jvm_interface.hpp"
#include <cstdint>
#include "heap.hpp"
#include "method_area.hpp"

using namespace std;

class InterfaceLoader{
private:
    static bool interfaceIs(ClassFileState state, string interface_name, MethodArea* method_area);
    static bool interfaceIsNot(ClassFileState state, string interface_name, MethodArea* method_area);


    static void linkInterface(string interface_name, MethodArea*);

    static void initializeInterface(string interface_name, MethodArea*);

public:
    static int resolveInterface(string interface_name, MethodArea*);
    static PrimitiveType* resolveSymbol(Heap*, MethodArea*, string symbol);

};



#endif
