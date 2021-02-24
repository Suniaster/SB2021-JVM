#include <stdio.h>
#include "../include/class_file.hpp"
#include <iostream>
#include "stdio.h"

int main(int argc, char **argv){
  cout << argv[1] << endl;
  ClassFile* class_file = new ClassFile(argv[1]);

  class_file->loadClass();
  class_file->printClass();

  return 0;
}
