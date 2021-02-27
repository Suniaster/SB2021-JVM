#include <stdio.h>
#include "../include/class_file.hpp"
#include <iostream>
#include "stdio.h"
#include "memory"

int main(int argc, char **argv){

  if(argv[1] == NULL){
      cout << "Nenhum arquivo inserido"<< endl;
      return 0;
  }
  unique_ptr<ClassFile> class_file (new ClassFile(argv[1]));

  class_file->loadClass();
  class_file->printClass();

  return 0;
}
