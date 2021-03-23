#include "../include/file_reader.hpp"
#include <fstream>
#include <iostream>

void FileReader::readFile(string file_name){
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

vector<BYTE> FileReader::getBytes(int size){
  vector<BYTE> temp;
  for(unsigned int i=this->position; i<this->position+size;i++){
    temp.push_back(this->file[i]);
  }
  this->position += size;
  return temp;
}
