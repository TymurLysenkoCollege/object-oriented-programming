#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Manager.h"


int main()
{
  srand(time(0));
  Manager mgr;
  
  mgr.storePerson(Person::getNewPerson("Tymur", 18, "SQL developer"));
  mgr.storePerson(Person::getNewPerson("Ryuk",  17, "Designer"));
  mgr.storePerson(Person::getNewPerson("Nick",  23, "Java developer"));
  mgr.storePerson(Person::getNewPerson("Oleg", 42, ".NET TL"));
  mgr.storePerson(Person::getNewPerson("Flint", 37, "Coffee Machine"));

  mgr.outputPeople();

  system("pause");
  return 0;
}
