#include "../../include/interpretador/execution_engine.hpp"
#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/reference_resolver.hpp"

void ExecutionEngine::loadMethodArea(string load_class_name){
  ClassFile* inserted_class;
  string super_name = load_class_name;
  do{
    load_class_name = super_name;
    inserted_class  = method_area.insertNewClass(load_class_name);
    super_name      = inserted_class->getSuperClassName();
  } while(load_class_name != "java/lang/Object");
  
  this->heap = Heap::getInstance();
}

void ExecutionEngine::start(){

  // A inicializacao da jvm consiste em:
  // Achar classe inicial (que tem a main nela)
  // Fazer Load, Link e Initalize dela
  // Rodar a main

  this->threads.push_back(
    new Thread(&this->method_area)
  );
  this->main_thread = this->threads[0];

  string inital_class_name = this->method_area.getMainMethod()->class_file->getThisClassName();

  this->main_thread->runMain();
}

ExecutionEngine* ExecutionEngine::instance = 0;
ExecutionEngine* ExecutionEngine::getInstance(){
  if(instance==0){
    ExecutionEngine::instance = new ExecutionEngine();
  }
  return ExecutionEngine::instance ;
};