#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__
class ClassFile;

#include <vector>
#include <string>
#include "./file_reader.hpp"
#include "./cp_info.hpp"
#include <cstdint>

using namespace std;

class ClassFile{
  private:
    uint32_t magic_number;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    
    vector<CpInfo*> constant_pool;
    void loadConstantPool();

  public:
    FileReader *file_reader;
    ClassFile(string file_name);

    void loadClass();
    void printClass();


};

#endif