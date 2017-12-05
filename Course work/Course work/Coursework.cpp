#include "stdafx.h"
#include <iostream>
#include "CController.h"

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "Rus");

  if (argc == 1)
  {
    cout << "The program can't be executed without parameters!\n" /*"Программа не может работать без параметров!"*/ << endl;

    exit(2);
  }

  if (argc < 5)
  {
    cout << "Too few parameters!\n" /*"Слишком мало параметров при вызове программы!\n"*/;

    exit(3);
  }

  if ( strcmp(argv[1], "-enc") != 0
    && strcmp(argv[1], "-dec") != 0 )
  {
    cout << "Wrong command format!" //"Неверный формат команды!"
            "\nYou can use either enc or dec" /*"\nВ параметре mode могут быть только enc или dec!"*/ << endl;

    exit(4);
  }

  if (strlen(argv[2]) != (KEY_SIZE / 8))
  {
    cout << "Wrong command format!" //"Неверный формат команды!"
            "\nKey should contain 8 symbols!" /*"\nРазмер ключа должен быть равным 8!"*/ << endl;

    exit(5);
  }

  cController Chipper;
  long long result = 0;
  byte ourKey[9]   = "\0";

  for (int i = 0; i < (KEY_SIZE / 8); i++)
  {
    ourKey[i] = (byte)argv[2][i];
  }

  switch (argv[1][1])
  {
    case 'e':
    {
      result = Chipper.encrypt(ourKey, argv[3], argv[4]);

      break;
    }

    case 'd':
    {
      string srcFile(argv[3]);
      string trgFile(argv[4]);

      result = Chipper.decrypt(ourKey, srcFile, trgFile); // , argv[3], argv[4]);

      break;
    }
  }

  switch (argv[1][1])
  {
    case 'e':
    {
      cout << "The file was successfully encrypted.\n" /*"Файл успешно зашифрован.\n"*/;
      break;
    }
    case 'd':
    {
      cout << "The file was successfully decrypted.\n" /*"Файл успешно расшифрован.\n"*/;
    }
  }

  system("pause");
  return 0;
}
