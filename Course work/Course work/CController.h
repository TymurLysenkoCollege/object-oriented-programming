#pragma once

#include "define.h"

class cController
{
  public:

    long long encrypt(byte key[KEY_SIZE / 8], string src_filename
                    , string dst_filename, eChipperMode cryptMode = ecb);
    long long decrypt(byte key[KEY_SIZE / 8], string src_filename
                    , string dst_filename);
};
