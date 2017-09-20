#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Manager.h"


int main()
{
  srand(time(0));
  Manager mgr;
  unsigned int sortOption = 0;
  
  mgr.storePerson(Person::getNewPerson("Tymur", 18, "SQL developer"));
  mgr.storePerson(Person::getNewPerson("Ryuk",  17, "Designer"));
  mgr.storePerson(Person::getNewPerson("Nick",  23, "Java developer"));
  mgr.storePerson(Person::getNewPerson("Oleg",  42, ".NET TL"));
  mgr.storePerson(Person::getNewPerson("Flint", 37, "Coffee Machine"));

  std::cout << "Choose sorting option:\n"
               "1 for sorting by name\n"
               "2 for sorting by age\n"
               "3 for sorting by speciality\n"
               "Any other for sorting by all 3 parameters simultaneously\n";
  std::cin >> sortOption;

  mgr.outputPeople(sortOption);

  system("pause");
  return 0;
}
