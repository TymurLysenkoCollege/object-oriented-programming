#include "stdafx.h"
#include <iostream>
#include <regex>
#include "MixNum.h"

int main()
{
  std::string input;
  bool repeat = true;

  while (repeat)
  {
    std::cout << "Enter 1-st fraction (for example: 1|13/3)" << "\n";
    std::getline(std::cin, input);

    std::regex  fractionPat(R"((\d+)\|(\d+)\/(\d+))");
    std::smatch fraction;

    std::regex_match(input, fraction, fractionPat);

    MixNum* fractionA;

    try
    {
      fractionA = new MixNum(  std::stod(fraction.str(1))
                             , std::stod(fraction.str(2))
                             , std::stod(fraction.str(3)));
    }
    catch (std::exception ex)
    {
      std::cout << ex.what() << "\n";
      bool repeat = true;
      continue;
    }

    std::cout << "Enter 2-nd fraction" << "\n";
    std::getline(std::cin, input);

    std::regex_match(input, fraction, fractionPat);

    MixNum* fractionB;

    try
    {
      fractionB = new MixNum(  std::stod(fraction.str(1))
                             , std::stod(fraction.str(2))
                             , std::stod(fraction.str(3)));
    }
    catch (std::exception ex)
    {
      std::cout << ex.what() << "\n";
      bool repeat = true;
      continue;
    }

    MixNum::show(*fractionA);
    std::cout << " + ";
    MixNum::show(*fractionB);
    std::cout << " = ";
    MixNum::show(MixNum::add(fractionA, fractionB));
    std::cout << "\n";

    MixNum::show(*fractionA);
    std::cout << " - ";
    MixNum::show(*fractionB);
    std::cout << " = ";
    MixNum::show(MixNum::subtract(*fractionA, *fractionB));
    std::cout << "\n";

    MixNum::show(*fractionA);
    std::cout << " * ";
    MixNum::show(*fractionB);
    std::cout << " = ";
    MixNum::show(MixNum::multiply(*fractionA, *fractionB));
    std::cout << "\n";

    MixNum::show(*fractionA);
    std::cout << " / ";
    MixNum::show(*fractionB);
    std::cout << " = ";
    MixNum::show(MixNum::divide(*fractionA, *fractionB));
    std::cout << "\n";

    repeat = 0;

    delete fractionA;
    delete fractionB;
  }

  std::cout << "\n";
  system("pause");
  return 0;
}
