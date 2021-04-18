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
    static pair<string, string> separateSymbol(string str, string delimiter);
  public:

    static JVMField* resolveStaticFieldSymbolicReference(string symbolic_reference, MethodArea*);
    static int resolveStringReference(string toResolve);
};



#endif
