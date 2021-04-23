#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/types/jvm_class.hpp"
#include "../../include/interpretador/types/jvm_field.hpp"
#include "../../include/interpretador/execution_engine.hpp"

void ClassLoader::linkClass(string class_name, MethodArea* method_area){
  Heap* heap = Heap::getInstance();
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

void ClassLoader::initializeClass(string class_name, MethodArea* method_area){
  ClassFile* class_file = method_area->getClassFile(class_name);
  
  Thread* main_thread =  ExecutionEngine::getInstance()->main_thread;
  main_thread->invokeStaticMethod(class_name, "<clinit>", NULL);

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
  ClassFile* class_file = method_area->getClassFile(class_name);
  return class_file->state >= state;
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