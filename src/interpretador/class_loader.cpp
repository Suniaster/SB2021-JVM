#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/types/jvm_class.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"
#include "../../include/interpretador/execution_engine.hpp"

void ClassLoader::linkClass(string class_name, MethodArea* method_area){
  Heap* heap = Heap::getInstance();
  JVMClass* linking_class = new JVMClass(class_name);

  linking_class->initializeFields();

  linking_class->class_file->heap_ref = heap->storeComponent(linking_class);

  linking_class->class_file->state = LINKED;
}

void ClassLoader::initializeClass(string class_name, MethodArea* method_area){
  ClassFile* class_file = method_area->getClassFile(class_name);
  
  if(method_area->classHasMethod(class_name, "<clinit>")){
    Thread newThread(method_area);
    newThread.invokeStaticMethod(class_name, "<clinit>", NULL);
    newThread.start();
  }

  class_file->state = INITIALIZED;
}

void ClassLoader::loadClass(string class_name, MethodArea* method_area){
  ClassFile* inserted_class;
  string super_name = class_name;

  do{
    class_name = super_name;
    if(VERBOSE_CLASS_LOADER){
      cout << "CLASSLOADER: loading class " << class_name << endl;
    }
    inserted_class  = method_area->insertNewClass(class_name);
    super_name      = inserted_class->getSuperClassName();
  } while(class_name != "java/lang/Object");
}

bool ClassLoader::classIs(ClassFileState state, string class_name, MethodArea* method_area){
  try{
    ClassFile* class_file = method_area->getClassFile(class_name);
    return class_file->state >= state;
  }
  catch(const std::exception& e){
    return false;
  }
}

bool ClassLoader::classIsNot(ClassFileState state, string class_name, MethodArea* method_area){
  return !ClassLoader::classIs(state, class_name, method_area);
}

int ClassLoader::resolveClass(string class_name, MethodArea* method_area){
  if(ClassLoader::classIsNot(LOADED, class_name, method_area)){
    ClassLoader::loadClass(class_name, method_area);
  }

  if(ClassLoader::classIsNot(LINKED, class_name, method_area)){
    ClassLoader::linkClass(class_name, method_area);
  }

  if(ClassLoader::classIsNot(INITIALIZED, class_name, method_area)){
    ClassLoader::initializeClass(class_name, method_area);
  }

  // TODO: Resolver super-classes

  ClassFile* class_file = method_area->getClassFile(class_name);
  return class_file->heap_ref;
}