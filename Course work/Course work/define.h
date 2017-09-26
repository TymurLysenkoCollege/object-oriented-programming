#pragma once

#include <fstream>

using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;

const int KEY_SIZE = 64;

enum eChipperMode
{
    ecb
  , gamma
  , efb
  , cheek
};

struct sCryptorHeader
{
  sCryptorHeader() {}
  sCryptorHeader(char* cName, eChipperMode eMode, long long files);

  char chipperName[12];
  eChipperMode mode;
  long long fileLen;
};
