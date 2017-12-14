#include "CController.h"

int cController::GetByteOfText(byte* buf, ifstream& file)
{
  int count = 0;
  char buf1;
  byte currBytes[BLOCK_SIZE / 8 + 1] = "\0";

  while ((!file.eof()) && (count < BLOCK_SIZE / 8))
  {
    file.get(buf1);

    if (!file.eof())
    {
      currBytes[count] = (byte)buf1;
      count++;
    }
  }

  if (count == 0)
  {
    return 0;
  }

  if (count != BLOCK_SIZE / 8)
  {
    srand(rand());

    while (count < BLOCK_SIZE / 8)
    {
      currBytes[count] = byte(rand() % 256);
      count++;
    }
  }

  for (int i = 0; i < BLOCK_SIZE / 8; i++)
  {
    buf[i] = currBytes[i];
  }

  return 1;
}

long long cController::GetFileSize(ifstream& file)
{
  streamoff begin;
  streamoff end;
  long long size;

  begin = file.tellg();

  file.seekg(0, ios::end);

  end = file.tellg();

  size = end - begin;

  file.seekg(0, ios::beg);

  return size;
}

long long cController::encrypt(  byte key[KEY_SIZE / 8], string src_filename
                               , string dst_filename, eChipperMode cryptMode)
{
  ifstream iSrcFile(src_filename.c_str(), ios::in | ios::_Nocreate | ios::binary);

  if (!iSrcFile)
  {
    throw "Исходного файла не существует!";
  }

  long long llFileSize = GetFileSize(iSrcFile);

  ofstream oDestFile(dst_filename.c_str(), ios::out | ios::binary);

  if (!oDestFile)
  {
    iSrcFile.close();

    throw "Невозможно создать файл для записи!";
  }

  byte bTextBlock[BLOCK_SIZE / 8 + 1] = "\0";
  sCryptorHeader schHeader(const_cast<char*>(CHIPPER_NAME), cryptMode, llFileSize);

  oDestFile.write((char*)&schHeader, sizeof(schHeader));

  while (iSrcFile)
  {
    if (GetByteOfText(bTextBlock, iSrcFile))
    {
      crypt.encryptBlock(bTextBlock, key);
      oDestFile.write((const char*)bTextBlock, BLOCK_SIZE / 8);
    }
  }

  iSrcFile.close();
  oDestFile.close();

  return llFileSize;
}

long long cController::decrypt(byte key[KEY_SIZE / 8], string src_filename, string dst_filename)
{
  ifstream iSrcFile(src_filename.c_str(), ios::in | ios::_Nocreate | ios::binary);

  if (!iSrcFile)
  {
    throw "Исходного файла не существует!";
  }

  sCryptorHeader schHeader;

  iSrcFile.read((char*)&schHeader, sizeof(schHeader));

  if (strcmp(schHeader.chipperName, CHIPPER_NAME) != 0)
  {
    iSrcFile.close();

    throw "Невозможно расшифровать криптограмму, использовался другой шифр!";
  }

  ofstream oDestFile(dst_filename.c_str(), ios::out | ios::binary);

  if (!oDestFile)
  {
    iSrcFile.close();

    throw "Невозможно создать файл для записи!";
  }

  byte bTextBlock[BLOCK_SIZE / 8 + 1] = "\0";
  long long size = 0;

  while (!iSrcFile.eof())
  {
    if (GetByteOfText(bTextBlock, iSrcFile))
    {

      crypt.decryptBlock(bTextBlock, key);

      for (int i = 0; i < (BLOCK_SIZE / 8) && size < schHeader.fileLen; i++)
      {
        oDestFile.put(bTextBlock[i]);
        size++;
      }

    }
  }

  iSrcFile.close();
  oDestFile.close();

  return schHeader.fileLen;
}
