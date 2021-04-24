#include "../include/file_reader.hpp"
#include <fstream>
#include <iostream>

string FileReader::file_path = "";

void FileReader::readFile(string file_name){

    file_name = FileReader::file_path + file_name + ".class";


  // open the file:
  streampos fileSize;

  ifstream file_read(file_name, ios::binary);
  // get its size:
  file_read.seekg(0, ios::end);
  fileSize = file_read.tellg();
  file_read.seekg(0, ios::beg);


  // read the data:
  vector<BYTE> fileData(fileSize);
  file_read.read((char *)&fileData[0], fileSize);

  for (unsigned int i=0; i<fileData.size(); i++){
    this->file.push_back(fileData[i]);
  }
  this->file_name = file_name;

  file_read.close();
}

string FileReader::getFileName(){
    return this->file_name;
}

void FileReader::setFilePath(string full_path) {
    string file_path = "";
    bool path_begin = false;

    for (int i = full_path.size(); i >= 0 ; i--) {
        if (full_path[i] == '/'){
            path_begin = true;
        }
        if(path_begin){
            file_path = full_path[i] + file_path;
        }
    }

    FileReader::file_path = file_path;

}

vector<BYTE> FileReader::getBytes(int size){
  vector<BYTE> temp;
  for(unsigned int i=this->position; i<this->position+size;i++){
    temp.push_back(this->file[i]);
  }
  this->position += size;
  return temp;
}

void FileReader::checkFileExists(string file_path) {

    ifstream file(file_path);
    if (!file.good()) {
        throw std::invalid_argument("Esse arquivo não existe");
    }
    file.close();

}

string FileReader::returnFileName(string full_path) {
    bool class_begin = false;
    string file_name  = "";

    for (int i = full_path.size(); i >= 0 ; i--) {
        if (full_path[i] == '/'){
            break;
        }
        if(class_begin){
            file_name = full_path[i] + file_name;
        }
        if (full_path[i] == '.'){
            class_begin = true;
        }


    }
    return file_name;
}

