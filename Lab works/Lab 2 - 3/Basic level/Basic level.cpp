#include "stdafx.h"
#include "BasicClass.h"
#include <iostream>

int main()
{
  int x = 0;
  int y = 0;
  int z = 0;
  std::cout << "Enter x, y and z:\n";
  std::cin >> x >> y >> z;

  BasicClass bc(x, y, z);

  std::cout << "func(x, y, z) = " << bc.func() << "\n";

  system("pause");
  return 0;
}

