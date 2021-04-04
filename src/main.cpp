#include "../include/class_file.hpp"
#include "../include/interpretador/execution_engine.hpp"
#include <iostream>
#include <memory>
#include <fstream>

int main(int argc, char **argv){
  string file_path = "";
  file_path = argv[1];
  // TODO: trocar lugar de checagem
//   ifstream file("./tests/"+file_path);

//   if (file.good()) {
//       ClassFile *class_file = new ClassFile(file_path);

//       class_file->loadClass();
//       class_file->printClass();

//       delete class_file;
//    } else {
//       throw std::invalid_argument("Esse arquivo não existe");
//    }

//   file.close();

  ExecutionEngine execEng;
  execEng.loadMethodArea(file_path);

  execEng.start();
  
  return 0;
}
