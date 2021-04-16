#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__
class ClassFile;

#include <vector>
#include <string>
#include <cstdint>
#include <map>

#include "./cp_info.hpp"
#include "./file_reader.hpp"
#include "./field_info.hpp"
#include "./interface_info.hpp"
#include "./attribute_info.hpp"
#include "./method_info.hpp"

using namespace std;

typedef enum{
  READ, LOADED, LINKED , INITIALIZED 
} ClassFileState;

class ClassFile{
  private:
    uint32_t magic_number;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    uint16_t fields_count;
    uint16_t methods_count;
    uint16_t attributes_count;
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    uint16_t interfaces_count;

    void loadConstantPool();
    void loadAttributes();
    void printConstantPool();

    void loadFields();
    void printFields();

    void loadInterfaces();
    void printInterfaces();

    void loadMethods();
    void printMethods();
public:
    vector<MethodInfo*> methods;
    vector<CpInfo*> constant_pool;
    vector<AttributeInfo*> attributes;
    vector<InterfaceInfo*> interfaces;
    vector<FieldInfo*> fields;

    // Variaveis usadas pelo interpretador
    ClassFileState state;
    uint64_t heap_ref;

    FileReader *file_reader;
    ClassFile(string file_name);
    ~ClassFile();
    CpInfo* getConstantPoolEntry(int index);
    void loadClass();

    void printClass();
    string getConstantPoolUtf8String(int index);

    string beautifiedMajorVersion();
    string beautifiedAccessFlags(uint16_t access_flag, bool is_fields, bool is_methods);

    string getSuperClassName();
    string getThisClassName();
    template<typename T>
    void setAttribute(int n_bytes, T&attribute);
    template<typename T>
    void deleteVector(vector<T> &attributes);
};

/*** definindo templates ***/
template<typename T>
void ClassFile::setAttribute(int n_bytes, T& attribute){
  vector<BYTE> bytes_read = this->file_reader->getBytes(n_bytes);
  attribute = this->file_reader->vector2Int<T>(bytes_read);
}

template<typename T>
void ClassFile::deleteVector(vector<T> &attributes){
  for (T attr: attributes)
    delete attr;
}
#endif
