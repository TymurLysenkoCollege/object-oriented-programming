#pragma once

#include "define.h"
#include <utility>

class cEncryptor
{
  public:

    void encryptBlock(byte* block, byte* key);
    void decryptBlock(byte* block, byte* key);

  private:

    int InitTransform   (int new_index);
    int FinalTransform  (int new_index);
    int E_for_C         (int new_index);
    int E_for_D         (int new_index);
    int KeyCP           (int new_index);
    int ExpandTransfor_f(int new_index);
    int FinalTransfor_f (int new_index);

    void   GetNewKey (const string init_key, string& adv_key, int rank_size);
    string S_box     (string old_block, int S_box);
    void   F_function(string iner_block, string& out_block, const string key);

    tuple<string, string, string, string> baseEncryption(const byte* block, const byte* key);

    byte BitToNum(string& bit);
    void NumToBit(byte n, string& result);

    string XOR            (string left, string right);
    void   LeftCircleShift(string& str, int count);
};

