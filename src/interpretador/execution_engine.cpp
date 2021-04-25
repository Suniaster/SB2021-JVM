#include "../../include/interpretador/execution_engine.hpp"
#include "../../include/interpretador/class_loader.hpp"
#include "../../include/interpretador/reference_resolver.hpp"

void ExecutionEngine::loadMethodArea(string load_class_name){
  this->heap = Heap::getInstance();
  this->method_area = MethodArea::getInstance();

  ClassLoader::loadClass(load_class_name, this->method_area);
}

void ExecutionEngine::start(){

  // A inicializacao da jvm consiste em:
  // Achar classe inicial (que tem a main nela)
  // Fazer Load, Link e Initalize dela
  // Rodar a main

  this->threads.push_back(
    new Thread(this->method_area)
  );
  this->main_thread = this->threads[0];

  string inital_class_name = this->method_area->getMainMethod()->class_file->getThisClassName();

  this->main_thread->runMain();
}

ExecutionEngine* ExecutionEngine::instance = NULL;
ExecutionEngine* ExecutionEngine::getInstance(){
  if(instance==NULL){
    ExecutionEngine::instance = new ExecutionEngine();
  }
  return ExecutionEngine::instance ;
};
void ExecutionEngine::releaseInstance(){
  if(ExecutionEngine::instance != NULL){
    delete ExecutionEngine::instance;
    ExecutionEngine::instance = NULL;
  }
}

ExecutionEngine::~ExecutionEngine(){
  Heap::releaseInstance();
  MethodArea::realeaseInstance();
  this->heap = NULL;
  this->method_area = NULL;

  for(uint i=0;i<this->threads.size();i+=1){
    delete this->threads[i];
  }
  this->threads.clear();
}