#include "../../include/interpretador/reference_resolver.hpp"
#include "../../include/interpretador/types/jvm_class.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"
#include "../../include/interpretador/class_loader.hpp"

pair<string, string>  ReferenceResolver::separateSymbol(string str, string delimiter){
  size_t delimiter_pos = str.find(".");
  string class_name = str.substr(0, delimiter_pos);
  str.erase(0, delimiter_pos+1);

  pair<string, string> ret;
  ret.first = class_name;
  ret.second = str;
  
  return ret;
}


JVMField* ReferenceResolver::resolveStaticFieldSymbolicReference(string symbolic_reference, Heap* heap, MethodArea* method_area){
  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_reference, ".");
  string class_name = names.first;
  string field_name = names.second;

  int class_ref = ClassLoader::resolveClass(class_name, heap, method_area);
  JVMClass* resolved_class = (JVMClass*)heap->getReference(class_ref);

  JVMField* field = resolved_class->getField(field_name);

  return field;
}