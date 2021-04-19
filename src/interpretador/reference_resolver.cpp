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

JVMField* ReferenceResolver::resolveStaticFieldSymbolicReference(string symbolic_reference, MethodArea* method_area){
  Heap* heap = Heap::getInstance();

  pair<string,string> names = ReferenceResolver::separateSymbol(symbolic_reference, ".");
  string class_name = names.first;
  string field_name = names.second;

  int class_ref = ClassLoader::resolveClass(class_name, method_area);
  JVMClass* resolved_class = (JVMClass*)heap->getReference(class_ref);

  JVMField* field = resolved_class->getField(field_name);

  return field;
}

int ReferenceResolver::resolveClassName(string class_name, MethodArea* m_a){
  return ClassLoader::resolveClass(class_name, m_a);
}

bool ReferenceResolver::isValidClassName(string class_name){
  return class_name != "java/lang/System";
}