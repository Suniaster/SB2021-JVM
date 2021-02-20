#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__

#include <vector>
#include <string>
#include "./file_reader.hpp"
#include <cstdint>

using namespace std;

class ClassFile{
  private:
    uint32_t magic_number;
    void setMagic();

  public:
    FileReader *file_reader;
    ClassFile(string file_name);

    void loadClass();
    void printClass();
};

#endif