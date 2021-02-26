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
    unsigned int position = 0;
    vector<BYTE> file;
  public:

    void readFile(string);
    vector<BYTE> getBytes(int);

    template <typename T>
    T vector2Int(vector<BYTE> bytes);
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
#endif