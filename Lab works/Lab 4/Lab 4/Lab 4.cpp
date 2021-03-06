#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>

void promptRepeat(std::string reason, bool& repeat)
{
  char answer = 'y';

  std::cout << reason << "\n";
  std::cout << "Do you want to repeat? (y/n)\n";
  std::cin.ignore();
  std::cin >> answer;

  repeat = (answer == 'n') ? false : true ;
}

template <typename T>
T promptInput(std::string promptText, unsigned int inputBase)
{
  T inputNumber = 0;

  std::cout << "\n";
  std::cout << promptText << "\n";

  std::cin.ignore();
  switch (inputBase)
  {
    case 2 :
    {
      std::cin >> inputNumber;;

      break;
    }

    case 8 :
    {
      std::cin >> std::oct >> inputNumber;

      break;
    }

    case 10 :
    {
      std::cin >> std::dec >> inputNumber;

      break;
    }

    case 16 :
    {
      std::cin >> std::hex >> inputNumber;

      break;
    }

    default:
    {
      std::cout << inputBase << " is not supported base for an input\n";

      break;
    }
  }

  std::cin >> std::dec;

  return inputNumber;
}

template <typename T>
void printNumberAlignLeft(T number, unsigned int outputBase)
{
  switch (outputBase)
  {
    case 2:
    {
      break;
    }

    case 8:
    {
      std::cout << std::oct;

      break;
    }

    case 10:
    {
      std::cout << std::dec;

      break;
    }

    case 16:
    {
      std::cout << std::hex;

      break;
    }

    default:
    {
      std::cout << outputBase << " is not supported base for an onput\n";

      break;
    }
  }

  std::cout << number << " | " << std::dec << outputBase;
}

template <typename T>
void printNumberAlignRight(T number, unsigned int outputBase)
{
  std::cout << std::right << std::setw(90);

  switch (outputBase)
  {
    case 2:
    {
      break;
    }

    case 8:
    {
      std::cout << std::oct;

      break;
    }

    case 10:
    {
      std::cout << std::dec;

      break;
    }

    case 16:
    {
      std::cout << std::hex;

      break;
    }

    default:
    {
      std::cout << outputBase << " is not supported base for an onput\n";

      break;
    }
  }

  std::cout << number << " | " << std::dec << outputBase;
}

void printOutput(std::string title, unsigned int inputBase, unsigned int outputBase, unsigned int number)
{
  std::cout << "\n";
  std::cout << title << "\n";

  if (inputBase == 2)
  {
    printNumberAlignLeft<std::bitset<16>>(std::bitset<16>(number), inputBase);
  }
  else
  {
    printNumberAlignLeft <unsigned int>(number, inputBase);
  }

  if (outputBase == 2)
  {
    printNumberAlignRight<std::bitset<16>>(std::bitset<16>(number), outputBase);
  }
  else
  {
    printNumberAlignRight<unsigned int>(number, outputBase);
  }

  std::cout << "\n";
}

void printOutput(std::string title, unsigned int inputBase, unsigned int outputBase, std::bitset<16> number)
{
  std::cout << "\n";
  std::cout << title << "\n";

  
  if (inputBase == 2)
  {
    printNumberAlignLeft<std::bitset<16>>(number, inputBase);
  }
  else
  {
    printNumberAlignLeft <unsigned int>(number.to_ulong(), inputBase);
  }

  if (outputBase == 2)
  {
    printNumberAlignRight<std::bitset<16>>(number, outputBase);
  }
  else
  {
    printNumberAlignRight<unsigned int>(number.to_ulong(), outputBase);
  }

  std::cout << "\n";
}

void printMath(std::string title, unsigned int outputBase, unsigned int left, unsigned int right)
{
  std::cout << "\n";
  std::cout << title << "\n";

  switch (outputBase)
  {
    case 2:
    {
      std::bitset<16> sum  = std::bitset<16>(left + right);
      std::bitset<16> diff = std::bitset<16>(left - right);
      std::bitset<16> prod = std::bitset<16>(left * right);
      std::bitset<16> div  = std::bitset<16>(left / right);
      std::bitset<16> mod  = std::bitset<16>(left % right);

      std::cout << std::bitset<16>(left) << " + " << std::bitset<16>(right) << " = " << sum << "\n";
      std::cout << std::bitset<16>(left) << " - " << std::bitset<16>(right) << " = " << diff << "\n";
      std::cout << std::bitset<16>(left) << " * " << std::bitset<16>(right) << " = " << prod << "\n";
      std::cout << std::bitset<16>(left) << " / " << std::bitset<16>(right) << " = " << div << "\n";
      std::cout << std::bitset<16>(left) << " % " << std::bitset<16>(right) << " = " << mod << "\n";

      break;
    }

    case 8 :
    {
      unsigned int sum  = unsigned int(left + right);
      unsigned int diff = unsigned int(left - right);
      unsigned int prod = unsigned int(left * right);
      unsigned int div  = unsigned int(left / right);
      unsigned int mod  = unsigned int(left % right);

      std::cout << std::oct;

      std::cout << left << " + " << right << " = " << sum << "\n";
      std::cout << left << " - " << right << " = " << diff << "\n";
      std::cout << left << " * " << right << " = " << prod << "\n";
      std::cout << left << " / " << right << " = " << div << "\n";
      std::cout << left << " % " << right << " = " << mod << "\n";

      break;
    }

    case 10 :
    {
      unsigned int sum  = unsigned int(left + right);
      unsigned int diff = unsigned int(left - right);
      unsigned int prod = unsigned int(left * right);
      unsigned int div  = unsigned int(left / right);
      unsigned int mod  = unsigned int(left % right);

      std::cout << std::dec;

      std::cout << left << " + " << right << " = " << sum << "\n";
      std::cout << left << " - " << right << " = " << diff << "\n";
      std::cout << left << " * " << right << " = " << prod << "\n";
      std::cout << left << " / " << right << " = " << div << "\n";
      std::cout << left << " % " << right << " = " << mod << "\n";

      break;
    }

    case 16 :
    {
      unsigned int sum  = unsigned int(left + right);
      unsigned int diff = unsigned int(left - right);
      unsigned int prod = unsigned int(left * right);
      unsigned int div  = unsigned int(left / right);
      unsigned int mod  = unsigned int(left % right);

      std::cout << std::hex;

      std::cout << left << " + " << right << " = " << sum << "\n";
      std::cout << left << " - " << right << " = " << diff << "\n";
      std::cout << left << " * " << right << " = " << prod << "\n";
      std::cout << left << " / " << right << " = " << div << "\n";
      std::cout << left << " % " << right << " = " << mod << "\n";

      break;
    }

    default:
    {
      std::cout << std::dec << "Can't do math for base " << outputBase;

      break;
    }
  }

  std::cout << "\n";
}

unsigned int main()
{
  bool repeat = true;

  while (repeat)
  {
    unsigned int inputBase = 10;
    std::cout << "Enter a base for input (2, 8, 10, 16):\n";
    std::cin  >> inputBase;

    unsigned int outputBase = 10;
    std::cout << "\n";
    std::cout << "Enter a base for output (2, 8, 10, 16):\n";
    std::cin  >> outputBase;

    if (inputBase == 2)
    {
      std::bitset<16> left  = std::bitset<16>(0);
      std::bitset<16> right = std::bitset<16>(0);

      left  = promptInput<std::bitset<16>>("Input 1-st number (positive):", inputBase);
      right = promptInput<std::bitset<16>>("Input 2-nd number (positive):", inputBase);

      printOutput("1-st number:", inputBase, outputBase, left);
      printOutput("2-nd number:", inputBase, outputBase, right);

      printMath(  "Math operations for " + std::to_string(outputBase) + " base:"
                , outputBase, left.to_ulong(), right.to_ulong());
    }
    else
    {
      unsigned int left = 0;
      unsigned int right = 0;

      left  = promptInput<unsigned int>("Input 1-st number (positive):", inputBase);
      right = promptInput<unsigned int>("Input 2-nd number (positive):", inputBase);

      printOutput("1-st number:", inputBase, outputBase, left);
      printOutput("2-nd number:", inputBase, outputBase, right);


      printMath(  "Math operations for " + std::to_string(outputBase) + " base:"
                , outputBase, left, right);
    }


    std::cout << "\n";
    promptRepeat("The program is finished", repeat);
  }

  return 0;
}
