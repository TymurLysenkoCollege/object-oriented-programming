#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include "Vorker.h"
#pragma warning(disable : 4996)

int main()
{
  struct tm* custDate = new tm();
  custDate->tm_year = 115;
  custDate->tm_mon  = 6;
  custDate->tm_mday = 20;
  custDate->tm_hour = 10;
  custDate->tm_min  = 30;
  custDate->tm_sec  = 45;

  Vorker ryuk(1, 500, "Ryuk", "Languages", "Top philologist", mktime(custDate));

  std::cout << ryuk << "\n";

  custDate->tm_year = 113;
  custDate->tm_mon  = 10;
  custDate->tm_mday = 4;
  custDate->tm_hour = 17;
  custDate->tm_min  = 28;
  custDate->tm_sec  = 37;

  Vorker tim(2, 500, "Tim", "IT", "Top programmer", mktime(custDate));

  std::cout << tim << "\n";

  ryuk += tim;

  std::cout << ryuk << "\n"
            << tim  << "\n";



  std::system("pause");
  return 0;
}

