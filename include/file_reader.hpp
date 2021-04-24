#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <vector>
#include <string>
#include <cstdint>
#include <iostream>

typedef unsigned char BYTE;
using namespace std;

class FileReader{
  private:
    vector<BYTE> file;
    string file_name;
    static string file_path;

  public:
    unsigned int position = 0;

    string getFileName();

    void readFile(string);
    vector<BYTE> getBytes(int);
    static void setFilePath(string);
    static void checkFileExists(string);
    static string returnFileName(string);

    template <typename T>
    T vector2Int(vector<BYTE> bytes);

    template<typename T>
    void readBytes(int n_bytes, T&attribute);
};

/*** definindo templates ***/
template <typename T>
T FileReader::vector2Int(vector<BYTE> bytes){
  T temp = 0;
  for(long unsigned int i=0; i< bytes.size();i++){
    BYTE masked_bytes = (bytes[i] & 0xff);
    int shift = ((bytes.size()-i-1)*8);
    temp |= masked_bytes << shift;
  }
  return temp;
}

template<typename T>
void FileReader::readBytes(int n_bytes, T& attribute){
  vector<BYTE> bytes_read = this->getBytes(n_bytes);
  attribute = this->vector2Int<T>(bytes_read);
}
#endif
