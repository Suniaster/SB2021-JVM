#ifndef __CLASS_LOADER_H__
#define __CLASS_LOADER_H__

#include "./types/component_type.hpp"
#include "./types/jvm_class.hpp"
#include <cstdint>
#include "heap.hpp"
#include "method_area.hpp"

using namespace std;

#define VERBOSE_CLASS_LOADER 1

class ClassLoader{
  private:
    static bool classIs(ClassFileState state, string class_name, MethodArea* method_area);
    static bool classIsNot(ClassFileState state, string class_name, MethodArea* method_area);

    // Cria as estutas necessarias no heap para essa classe
    static void linkClass(string class_name, MethodArea*);
  
    static void initializeClass(string class_name, MethodArea*);
  
  public:
    static void loadClass(string class_name, MethodArea*);
    static int resolveClass(string class_name, MethodArea*);
    static PrimitiveType* resolveSymbol(Heap*, MethodArea*, string symbol);

};



#endif
