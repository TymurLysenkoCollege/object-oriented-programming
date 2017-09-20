#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Manager.h"


int main()
{
  srand(time(0));
  Manager mgr;
  unsigned int input = 0;
  
  std::cout << "Do you want to enter values by yourself (1) "
               "or use predefined (any other value)?\n";
  std::cin >> input;

  switch (input)
  {
    case 1:
    {
      std::cout << "How many people do you want to input?\n";
      std::cin >> input;

      std::string name;
      std::string speciality;
      unsigned int age;

      for (unsigned int i = 0; i < input; ++i)
      {
        std::cout << "Enter a NAME for [" << i << "] element:\n";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter a SPECIALITY for [" << i << "] element:\n";
        std::cin.ignore();
        std::getline(std::cin, speciality);

        std::cout << "Enter an age for [" << i << "] element:\n";
        std::cin >> age;

        mgr.storePerson(Person::getNewPerson(name, age, speciality));
      }
      std::cout << "\n";

      break;
    }

    default:
    {
      mgr.storePerson(Person::getNewPerson("Tymur", 18, "SQL developer"));
      mgr.storePerson(Person::getNewPerson("Ryuk",  17, "Designer"));
      mgr.storePerson(Person::getNewPerson("Nick",  23, "Java developer"));
      mgr.storePerson(Person::getNewPerson("Oleg",  42, ".NET TL"));
      mgr.storePerson(Person::getNewPerson("Flint", 37, "Coffee Machine"));

      break;
    }
  }

  std::cout << "Choose sorting option:\n"
               "1 for sorting by name\n"
               "2 for sorting by age\n"
               "3 for sorting by speciality\n"
               "Any other for sorting by all 3 parameters simultaneously\n";
  std::cin >> input;

  mgr.outputPeople(input);

  system("pause");
  return 0;
}
