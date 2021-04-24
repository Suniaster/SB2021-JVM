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
    static int resolveObjectByDescriptor(string descriptor, MethodArea*m_a);
  public:
    static pair<string, string> separateSymbol(string str, string delimiter);

    static int resolveClassName(string class_name, MethodArea*);
    static int resolveInterfaceName(string class_name, MethodArea*);
    static JVMField* resolveStaticFieldSymbolicReference(string symbolic_reference, MethodArea*);
    static int allocateArray(string descriptor, MethodArea*m_a, vector<uint64_t> dims);
    static int resolveStringReference(string toResolve);
    static bool isValidClassName(string class_name);
};



#endif
