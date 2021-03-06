#include "stdafx.h"
#include <regex>
#include <string>
#include <iostream>
#include "FracNum.h"

int main()
{
  std::string input;
  bool repeat = true;

  while (repeat)
  {
    std::cout << "Enter 1-st fraction (for example: 13/3)" << "\n";
    std::getline(std::cin, input);

    std::regex  fractionPat(R"((\d+)\/(\d+))");
    std::smatch fraction;

    std::regex_match(input, fraction, fractionPat);

    FracNum* fractionA;

    try
    {
      fractionA = new FracNum(  std::stod(fraction.str(1))
                              , std::stod(fraction.str(2)) );
    }
    catch (std::exception ex)
    {
      std::cout << ex.what() << "\n";
      continue;
    }

    std::cout << "Enter 2-nd fraction" << "\n";
    std::getline(std::cin, input);

    std::regex_match(input, fraction, fractionPat);

    FracNum* fractionB;

    try
    {
      fractionB = new FracNum(  std::stod(fraction.str(1))
                              , std::stod(fraction.str(2)) );
    }
    catch (std::exception ex)
    {
      std::cout << ex.what() << "\n";
      continue;
    }

    FracNum::show(*fractionA);
    std::cout << " + ";
    FracNum::show(*fractionB);
    std::cout << " = ";
    FracNum::show(FracNum::add(fractionA, fractionB));
    std::cout << "\n";

    FracNum::show(*fractionA);
    std::cout << " - ";
    FracNum::show(*fractionB);
    std::cout << " = ";
    FracNum::show(FracNum::subtract(*fractionA, *fractionB));
    std::cout << "\n";

    repeat = 0;

    delete fractionA;
    delete fractionB;
  }
  
  std::cout << "\n";
  system("pause");
  return 0;
}
