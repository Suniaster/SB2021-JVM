#include "../../include/interpretador/execution_engine.hpp"
#include "../../include/interpretador/class_loader.hpp"


void ExecutionEngine::loadMethodArea(string load_class_name){
  ClassFile* inserted_class;
  string super_name = load_class_name;
  do{
    load_class_name = super_name;
    inserted_class  = method_area.insertNewClass(load_class_name);
    super_name      = inserted_class->getSuperClassName();
  } while(load_class_name != "java/lang/Object");
  
}

void ExecutionEngine::start(){

  // A inicializacao da jvm consiste em:
  // Achar classe inicial (que tem a main nela)
  // Fazer Load, Link e Initalize dela
  // Rodar a main

  this->threads.push_back(
    new Thread(&this->method_area, &this->heap)
  );

  string inital_class_name = this->method_area.getMainMethod()->class_file->getThisClassName();

  // cuida da parte de fazer Load e Link
  int heap_ref = ClassLoader::resolveClass(inital_class_name, &this->heap, &this->method_area);

  // Teste:
  ComponentType* t = this->heap.getReference(heap_ref);
  
  cout << "Componente armazenado eh: " << t->toString() << endl;


  this->threads[0]->runMain();
}