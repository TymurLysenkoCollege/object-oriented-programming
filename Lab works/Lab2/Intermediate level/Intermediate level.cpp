#include "stdafx.h"
#include <regex>
#include <string>
#include <iostream>
#include "FracNum.h"

template<typename Target = std::string, typename Source = std::string>
Target to(Source arg)
{
  std::stringstream interpreter;
  Target result;
  if (!(interpreter << arg)
    || !(interpreter >> result)
    || !(interpreter >> std::ws).eof())
  {
    throw runtime_error{ "to<>() failed" };
  }
  return result;
}

int main()
{
  std::string input;
  bool repeat = 1;

  while (repeat)
  {
    std::cout << "Enter 1-st fraction (for example: 13/3)" << "\n";
    std::cin.ignore();
    std::getline(std::cin, input);

    std::regex  fractionPat(R"((\d+\.?\d*)\/(\d+\.?\d*))");
    std::smatch fraction;

    std::regex_match(input, fraction, fractionPat);

    FracNum fractionA;

    try
    {
      fractionA = FracNum(  to<double>(fraction.str(1))
                          , to<double>(fraction.str(2)) );
    }
    catch (std::exception ex)
    {
      std::cout << ex.what();
      continue;
    }

    fractionA.show();

    repeat = 0;
  }
  
  system("pause");
  return 0;
}
