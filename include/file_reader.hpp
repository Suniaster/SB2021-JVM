#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <vector>
#include <string>
#include <cstdint>
#include <iostream>

typedef char BYTE;
using namespace std;

class FileReader{
  private:
    unsigned int position = 0;
    vector<BYTE> file;
  public:

    void readFile(string);
    vector<BYTE> getBytes(int);

    uint16_t vectorTo2Bytes(vector<BYTE>);
    uint32_t vectorTo4Bytes(vector<BYTE>);
};

#endif