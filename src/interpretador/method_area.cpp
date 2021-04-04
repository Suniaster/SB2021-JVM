#include "../../include/interpretador/method_area.hpp"


ClassFile* MethodArea::insertNewClass(string class_name){
  if(class_name == "java/lang/Object") class_name = "Object";
  ClassFile* new_class = new ClassFile(class_name+".class");

  new_class->loadClass();
  cout << "Inserindo classe: " << new_class->getThisClassName() << endl;
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

MethodInfo* MethodArea::getMainMethod(){
  // TODO: Dar throw caso main_method nao tenha sido setado;
  return this->main_method;
}