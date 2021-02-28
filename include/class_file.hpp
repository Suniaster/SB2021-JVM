#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__
class ClassFile;

#include <vector>
#include <string>
#include "./file_reader.hpp"
#include "./cp_info.hpp"
#include "./attribute_info.hpp"
#include <cstdint>

using namespace std;

class ClassFile{
  private:
    uint32_t magic_number;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    uint16_t attributes_count;
    
    vector<CpInfo*> constant_pool;
    vector<AttributeInfo*> attributes;

    void loadConstantPool();
    void loadAttributes();

    void printAttributes();
  public:
    FileReader *file_reader;
    ClassFile(string file_name);

    void loadClass();
    void printClass();

    template<typename T>
    void setAttribute(int n_bytes, T&attribute);
};

/*** definindo templates ***/
template<typename T>
void ClassFile::setAttribute(int n_bytes, T& attribute){
  vector<BYTE> bytes_read = this->file_reader->getBytes(n_bytes);
  attribute = this->file_reader->vector2Int<T>(bytes_read);
}
#endif