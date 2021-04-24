#include "../../include/interpretador/reference_resolver.hpp"
#include "../../include/interpretador/types/jvm_class.hpp"
#include "../../include/interpretador/types/jvm_interface.hpp"
#include "../../include/interpretador/types/array_type.hpp"
#include "../../include/interpretador/types/jvm_object.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"
#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/interface_loader.hpp"

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
  if(ReferenceResolver::isValidClassName(class_name)){
    return ClassLoader::resolveClass(class_name, m_a);
  }
  else return -1;
}

int ReferenceResolver::resolveObjectByDescriptor(string descriptor, MethodArea*m_a){
  if(descriptor == "Ljava/lang/String;" ){
    string type;
    type += descriptor[0];
    JVMType p_type = ComponentType::getTypeFromDescriptor(type);
    ComponentType* newprimitive = ComponentType::getDefaultValue(p_type);
    return Heap::getInstance()->storeComponent(newprimitive);
  }

  if(descriptor[0] == 'L'){
    string class_name;
    for(size_t j=1;j<descriptor.size();j+=1){
      if(descriptor[j] == ';') break;
      class_name += descriptor[j];
    }
    ReferenceResolver::resolveClassName(class_name, m_a);
    JVMObject* newObject = new JVMObject(class_name);
    newObject->initializeFields();
    return  Heap::getInstance()->storeComponent(newObject);
  }

  return -1;
}

int ReferenceResolver::allocateArray(string descriptor, MethodArea*m_a, vector<uint64_t> dims){
  if(descriptor[0] == '['){
    descriptor.erase(0, 1);
    JVMType array_type = ComponentType::getTypeFromDescriptor(descriptor);
    ArrayType* newarray = new ArrayType(array_type);

    uint64_t array_length = dims[0];
    dims.erase(dims.begin());

    for(size_t i=0;i<array_length;i+=1){
      if(descriptor[0] == '[' || descriptor[0] == 'L'){
        int ref = ReferenceResolver::allocateArray(descriptor, m_a, dims);
        PrimitiveType* new_el = new PrimitiveType(ref, Reference);
        newarray->insert(new_el);
      }
      else{
        ComponentType* newprimitive = ComponentType::getDefaultValue(array_type);
        newarray->insert(newprimitive);
      }
    }
    return Heap::getInstance()->storeComponent(newarray);;
  }
  else{
    return ReferenceResolver::resolveObjectByDescriptor(descriptor, m_a);
  }
}

int ReferenceResolver::resolveInterfaceName(string interface_name, MethodArea* m_a){
    return InterfaceLoader::resolveInterface(interface_name, m_a);
};

bool ReferenceResolver::isValidClassName(string class_name){
  return (
    class_name != "java/lang/System" &&
    class_name != "java/lang/String"
  );
}