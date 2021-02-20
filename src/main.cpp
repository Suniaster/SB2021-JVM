#include <stdio.h>
#include "../include/class_file.hpp"
#include <iostream>
#include "stdio.h"

int main(){
  ClassFile* class_file = new ClassFile("./Teste.class");

  class_file->loadClass();
  class_file->printClass();

  return 0;
}