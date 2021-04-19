#ifndef __REFERENCE_RESOLVER_H__
#define __REFERENCE_RESOLVER_H__

#include "./types/component_type.hpp"
#include "./types/jvm_class.hpp"
#include <cstdint>
#include "heap.hpp"
#include "method_area.hpp"
#include <utility>

using namespace std;

class ReferenceResolver{
  private:
  public:
    static pair<string, string> separateSymbol(string str, string delimiter);

    static int resolveClassName(string class_name, MethodArea*);
    static JVMField* resolveStaticFieldSymbolicReference(string symbolic_reference, MethodArea*);
    static int resolveStringReference(string toResolve);
    static bool isValidClassName(string class_name);
};



#endif