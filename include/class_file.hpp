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
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    
    template<typename T>
    void setAttribute(int n_bytes, T&attribute);

  public:
    FileReader *file_reader;
    ClassFile(string file_name);

    void loadClass();
    void printClass();
};

/*** definindo templates ***/
template<typename T>
void ClassFile::setAttribute(int n_bytes, T& attribute){
  vector<BYTE> bytes_read = this->file_reader->getBytes(n_bytes);
  attribute = this->file_reader->vector2Int<T>(bytes_read);
}
#endif