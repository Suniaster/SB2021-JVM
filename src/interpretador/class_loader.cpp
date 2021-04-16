#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/types/jvm_class.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"

void ClassLoader::linkClass(string class_name, Heap* heap, MethodArea* method_area){
  JVMClass* linking_class = new JVMClass(class_name);

  ClassFile* class_file = method_area->getClassFile(class_name);
  linking_class->setClassFile(class_file);


  // Link fields
  for(uint16_t i=0;i<class_file->fields.size();i+=1){
    FieldInfo* field = class_file->fields[i];

    if(field->isStatic()){
      JVMField* newFieldAlocated = new JVMField(field);
      heap->storeComponent(newFieldAlocated);
      linking_class->addField(newFieldAlocated);
    }
  }

  class_file->heap_ref = heap->storeComponent(linking_class);

  class_file->state = LINKED;
}

bool ClassLoader::classIs(ClassFileState state, string class_name, MethodArea* method_area){
  ClassFile* class_file = method_area->getClassFile(class_name);
  return class_file->state >= state;
}

bool ClassLoader::classIsNot(ClassFileState state, string class_name, MethodArea* method_area){
  return !ClassLoader::classIs(state, class_name, method_area);
}

int ClassLoader::resolveClass(string class_name, Heap* heap, MethodArea* method_area){
  if(ClassLoader::classIsNot(LOADED, class_name, method_area)){
    throw runtime_error("LoadError: "+class_name+" is not loaded");
  }

  if(ClassLoader::classIsNot(LINKED, class_name, method_area)){
    ClassLoader::linkClass(class_name, heap, method_area);
  }

  // TODO: Fazer inicializacao (chamar metodo clinit)

  // TODO: Resolver super-classes

  ClassFile* class_file = method_area->getClassFile(class_name);
  return class_file->heap_ref;
}