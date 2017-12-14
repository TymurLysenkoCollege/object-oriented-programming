#pragma once

#include <fstream>

using namespace std;

typedef unsigned char byte;
typedef unsigned int  uint;

const char CHIPPER_NAME[] = "DES";

const int KEY_SIZE = 64;
const int ADVANCED_KEY_SIZE = 48;

const int BLOCK_SIZE = 64;

const int RANK_SIZE = 16;

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

  sCryptorHeader(char* cName, eChipperMode eMode, long long files)
  {
    strcpy_s(chipperName, cName);
    mode    = eMode;
    fileLen = files;
  }

  char chipperName[12];
  eChipperMode mode;
  long long fileLen;
};
