#include "cEncryptor.h"
#include <tuple>

const uint S1[4][16] = {
                         {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                         {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                         {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                         {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
                       };

const uint S2[4][16] = {
                         {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                         {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                         {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                         {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
                       };

const uint S3[4][16] = {
                         {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                         {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                         {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                         {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
                       };

const uint S4[4][16] = {
                         {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                         {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                         {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                         {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
                       };

const uint S5[4][16] = {
                         { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9 },
                         { 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6 },
                         { 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
                         { 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 }
                       };

const uint S6[4][16] = {
                         { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
                         { 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8 },
                         { 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6 },
                         { 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 }
                       };

const uint S7[4][16] = {
                         { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1 },
                         { 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6 },
                         { 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2 },
                         { 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 }
                       };

const uint S8[4][16] = {
                         { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7 },
                         { 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2 },
                         { 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8 },
                         { 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }
                       };

void cEncryptor::NumToBit(byte n, string& result)
{
  uint n1 = static_cast<uint>(n);

  for (int c = result.size() - 1; c >= 0; --c)
  {
    if (n1 % 2)
    {
      result[c] = '1';
    }
    else
    {
      result[c] = '0';
    }

    n1 /= 2;
  }
}

byte cEncryptor::BitToNum(string& bit)
{
  byte res = 0;

  int  rank = bit.size() - 1;
  int* arr  = new int[rank + 1];

  for (int i = 0; i <= rank; ++i)
  {
    if (bit[i] == '0')
    {
      arr[i] = 0;
    }
    else
    {
      arr[i] = 1;
    }
  }

  for (int c = rank, i = 0; c >= 0; --c, ++i)
  {
    res += (arr[i] * pow(2.0, c));
  }

  delete[] arr;

  return res;
}

int cEncryptor::InitTransform(int new_index)
{
  int transform_array[] = {  58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28
                           , 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56
                           , 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9
                           , 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37
                           , 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::FinalTransform(int new_index)
{
  int transform_array[] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::ExpandTransfor_f(int new_index)
{
  int transform_array[] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::FinalTransfor_f(int new_index)
{
  int transform_array[] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::E_for_C(int new_index)
{
  int transform_array[] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::E_for_D(int new_index)
{
  int transform_array[] = { 63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

int cEncryptor::KeyCP(int new_index)
{
  int transform_array[] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
  int old_index = transform_array[new_index] - 1;

  return old_index;
}

void cEncryptor::LeftCircleShift(string& str, int count)
{
  string buf;
  int limit = str.size() - count;

  for (int i = 0; i < count; ++i)
  {
    buf += str[i];
  }

  for (int i = 0; i < limit; ++i)
  {
    str[i] = str[i + count];
  }

  for (int i = limit; i < str.size(); ++i)
  {
    str[i] = buf[i - limit];
  }
}

string cEncryptor::XOR(string left, string right)
{
  string result = "\0";

  for (int i = 0; i < left.size(); i++)
  {
    if (left[i] != right[i])
    {
      result += '1';
    }
    else
    {
      result += '0';
    }
  }

  return result;
}

void cEncryptor::GetNewKey(const string init_key, string& adv_key, int rank_size)
{
  string C    = "\0";
  string D    = "\0";
  string buff = "\0";

  for (int i = 0; i < 28; ++i)
  {
    C += init_key[E_for_C(i)];
    D += init_key[E_for_D(i)];
  }

  for (int rank = 1; rank <= rank_size; ++rank)
  {
    switch (rank)
    {
      case 1:
      case 2:
      case 9:
      case 16:
      {
        LeftCircleShift(C, 1);
        LeftCircleShift(D, 1);

        break;
      }

      default:
      {
        LeftCircleShift(C, 2);
        LeftCircleShift(D, 2);

        break;
      }
    }
  }

  buff = C + D;

  for (int i = 0; i < ADVANCED_KEY_SIZE; ++i)
  {
    adv_key[i] = buff[KeyCP(i)];
  }
}

string cEncryptor::S_box(string old_block, int S_box)
{
  string BitRow(2, 0);
  string BitCol(4, 0);
  string result(4, 0);
  uint   row;
  uint   col;

  BitRow[0] = old_block[5];
  BitRow[1] = old_block[0];

  for (int i = 0; i < 4; ++i)
  {
    BitCol[i] = old_block[i + 1];
  }

  row = BitToNum(BitRow);
  col = BitToNum(BitCol);

  switch (S_box)
  {
    case 1:
    {
      NumToBit(S1[row][col], result);

      break;
    }

    case 2:
    {
      NumToBit(S2[row][col], result);

      break;
    }
    case 3:
    {
      NumToBit(S3[row][col], result);

      break;
    }

    case 4:
    {
      NumToBit(S4[row][col], result);

      break;
    }

    case 5:
    {
      NumToBit(S5[row][col], result);

      break;
    }

    case 6:
    {
      NumToBit(S6[row][col], result);

      break;
    }

    case 7:
    {
      NumToBit(S7[row][col], result);

      break;
    }

    case 8:
    {
      NumToBit(S8[row][col], result);

      break;
    }
  }

  return result;
}

void cEncryptor::F_function(string iner_block, string& out_block, const string key)
{
  string buff;
  string sub_blocks(6, 0);
  string str_result = "\0";

  for (int i = 0; i < ADVANCED_KEY_SIZE; i++)
  {
    buff += iner_block[ExpandTransfor_f(i)];
  }

  buff = XOR(buff, key);

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      sub_blocks[j] = buff[6 * i + j];
    }

    str_result += S_box(sub_blocks, i + 1);
  }

  for (int i = 0; i < BLOCK_SIZE / 2; i++)
  {
    out_block[i] = str_result[FinalTransfor_f(i)];
  }
}

tuple<string, string, string, string> cEncryptor::baseEncryption(const byte* block, const byte* key)
{
  string bit_buf    = "\0";
  string A_side     = "\0";
  string B_side     = "\0";
  string symb_bytes = "\0";
  string str_key    = "\0";

  byte   buff[KEY_SIZE / 8 + 1] = "\0";
  string bytes(8, 0);

  for (int i = 0; i < 8; ++i)
  {
    NumToBit(block[i], bytes);
    symb_bytes += bytes;
  }

  for (int i = 0; i < KEY_SIZE / 8; ++i)
  {
    NumToBit(key[i], bytes);
    str_key += bytes;
  }

  for (int i = 0; i < BLOCK_SIZE; ++i)
  {
    bit_buf += symb_bytes[InitTransform(i)];
  }

  for (int i = 0; i < BLOCK_SIZE / 2; ++i)
  {
    A_side += bit_buf[i];
    B_side += bit_buf[BLOCK_SIZE / 2 + i];
  }

  return make_tuple(A_side, B_side, str_key, symb_bytes);
}


void cEncryptor::encryptBlock(byte* block, byte* key)
{
  auto initValues = baseEncryption(block, key);

  string A_side     = get<0>(initValues);
  string B_side     = get<1>(initValues);
  string str_key    = get<2>(initValues);
  string symb_bytes = get<3>(initValues);

  string A_buff = "\0";
  string B_buff = "\0";
  string str_rank_key(ADVANCED_KEY_SIZE, 0);

  for (int rank = 1; rank <= RANK_SIZE; ++rank)
  {
    A_buff = A_side;
    B_buff = B_side;

    GetNewKey(str_key, str_rank_key, rank);
    A_side = B_side;

    F_function(B_side, B_buff, str_rank_key);

    B_side = XOR(A_buff, B_buff);
  }

  string result = A_side + B_side;

  for (int i = 0; i < BLOCK_SIZE; i++)
  {
    symb_bytes[i] = result[FinalTransform(i)];
  }

  string fin_buf(8, 0);
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      fin_buf[i] = symb_bytes[8 * j + i];
    }

    block[j] = BitToNum(fin_buf);
  }
}

void cEncryptor::decryptBlock(byte * block, byte * key)
{
  auto initValues = baseEncryption(block, key);

  string A_side = get<0>(initValues);
  string B_side = get<1>(initValues);
  string str_key = get<2>(initValues);
  string symb_bytes = get<3>(initValues);

  string A_buff = "\0";
  string B_buff = "\0";
  string str_rank_key(ADVANCED_KEY_SIZE, 0);

  for (int rank = 1; rank <= RANK_SIZE; ++rank)
  {
    GetNewKey(str_key, str_rank_key, RANK_SIZE - rank + 1);
    B_side = A_side;

    F_function(A_side, A_buff, str_rank_key);

    A_side = XOR(A_buff, B_buff);
  }

  string result = A_side + B_side;

  for (int i = 0; i < BLOCK_SIZE; i++)
  {
    symb_bytes[i] = result[FinalTransform(i)];
  }

  string fin_buf(8, 0);
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      fin_buf[i] = symb_bytes[8 * j + i];
    }

    block[j] = BitToNum(fin_buf);
  }
}

/*
void cEncryptor::encryptBlock(byte* block, byte* key, int mode)
{
  string bit_buf    = "\0";
  string A_side     = "\0";
  string B_side     = "\0";
  string symb_bytes = "\0";
  string str_key    = "\0";

  string str_rank_key(ADVANCED_KEY_SIZE, 0);

  string A_buff = "\0";
  string B_buff = "\0";
  string result = "\0";

  string fin_buf(8, 0);

  byte   buff[KEY_SIZE / 8 + 1] = "\0";
  string bytes(8, 0);

  for (int i = 0; i < 8; ++i)
  {
    NumToBit(block[i], bytes);
    symb_bytes += bytes;
  }

  for (int i = 0; i < KEY_SIZE / 8; ++i)
  {
    NumToBit(key[i], bytes);
    str_key += bytes;
  }

  for (int i = 0; i < BLOCK_SIZE; ++i)
  {
    bit_buf += symb_bytes[InitTransform(i)];
  }

  for (int i = 0; i < BLOCK_SIZE / 2; ++i)
  {
    A_side += bit_buf[i];
    B_side += bit_buf[BLOCK_SIZE / 2 + i];
  }

  for (int rank = 1; rank <= RANK_SIZE; ++rank)
  {
    A_buff = A_side;
    B_buff = B_side;

    if (mode == 0)
    {
      GetNewKey(str_key, str_rank_key, rank);
      A_side = B_side;

      F_function(B_side, B_buff, str_rank_key);

      B_side = XOR(A_buff, B_buff);
    }
    else
    {
      GetNewKey(str_key, str_rank_key, RANK_SIZE - rank + 1);
      B_side = A_side;

      F_function(A_side, A_buff, str_rank_key);

      A_side = XOR(A_buff, B_buff);
    }
  }

  result = A_side + B_side;

  for (int i = 0; i < BLOCK_SIZE; i++)
  {
    symb_bytes[i] = result[FinalTransform(i)];
  }

  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      fin_buf[i] = symb_bytes[8 * j + i];
    }

    block[j] = BitToNum(fin_buf);
  }
}
*/
