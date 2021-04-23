#include "../../include/interpretador/method_area.hpp"


ClassFile* MethodArea::insertNewClass(string class_name){
  if(this->isAlreadyIncluded(class_name)){
    return this->getClassFile(class_name);
  }
  if(class_name == "java/lang/Object") class_name = "Object";
  ClassFile* new_class = new ClassFile(class_name+".class");

  new_class->loadClass();
  this->classes.push_back(new_class);

  this->searchMainMethod(new_class);
  return new_class;
}

void MethodArea::searchMainMethod(ClassFile* classfile){
  for(uint32_t i=0; i<classfile->methods.size();i+=1){
    MethodInfo* current_method = classfile->methods[i];

    // TODO: verificar public static
    if(current_method->getName() == "main"){ 
      this->main_method = current_method;
    }
  }
}

MethodInfo* MethodArea::getMethodByName(string class_name, string methodName){
  ClassFile* class_file = this->getClassFile(class_name);

  for(uint32_t i=0; i<class_file->methods.size();i+=1){
    MethodInfo* current_method = class_file->methods[i];

    if(current_method->getName() == methodName){ 
      return current_method;
    }
  }
  throw runtime_error("MethodError: " + methodName + " nao encontrado");
}

MethodInfo* MethodArea::getMainMethod(){
  // TODO: Dar throw caso main_method nao tenha sido setado;
  return this->main_method;
}

ClassFile* MethodArea::getClassFile(string class_name){
  for(uint16_t i=0;i<this->classes.size();i+=1){
    string evaluated_class_name = this->classes[i]->getThisClassName();
    if(evaluated_class_name == class_name){
      return this->classes[i];
    }
  }
  throw runtime_error("ClassError: " + class_name + " nao encontrado");
}

bool MethodArea::isAlreadyIncluded(string class_name){
  try{
    this->getClassFile(class_name);
    return true;
  }
  catch(const std::exception& e){
    return false;
  }
}