#include "../include/class_file.hpp"
#include "../include/interpretador/execution_engine.hpp"

#include <iostream>
#include <memory>
#include <fstream>
#include "../include/file_reader.hpp"

int main(int argc, char **argv){
  string file_path = "";
  file_path = argv[1];
  string  options = "";


    if(argc < 3){
        throw  std::runtime_error("No option given");
    }
    options = argv[2];

   FileReader::checkFileExists(file_path);

   FileReader::setFilePath(file_path);
   string file_name = FileReader::returnFileName(file_path);

    if (options.find("-t") != std::string::npos){
        ClassFile* class_file = new ClassFile(file_name);

        class_file->loadClass();
        class_file->printClass();
    }else if (options.find("-e") != std::string::npos){
        ExecutionEngine* execEng = ExecutionEngine::getInstance();
        execEng->loadMethodArea(file_name);

        execEng->start();
    }else {
        throw std::runtime_error("Invalid option");
    }

  

  Heap::getInstance()->clearHeap();

  return 0;
}
