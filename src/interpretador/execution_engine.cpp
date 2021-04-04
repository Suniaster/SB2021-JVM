#include "../../include/interpretador/execution_engine.hpp"



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
  this->threads.push_back(
    new Thread(&this->method_area)
  );

  this->threads[0]->runMain();
}