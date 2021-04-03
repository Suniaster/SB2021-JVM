#include "../../include/interpretador/method_area.hpp"


ClassFile* MethodArea::insertNewClass(string class_name){
  if(class_name == "java/lang/Object") class_name = "Object";
  ClassFile* new_class = new ClassFile(class_name+".class");

  new_class->loadClass();
  cout << "Inserindo classe: " << new_class->getThisClassName() << endl;
  classes.push_back(new_class);

  return new_class;
}