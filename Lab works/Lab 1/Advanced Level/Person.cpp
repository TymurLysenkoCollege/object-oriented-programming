#include "stdafx.h"
#include "Person.h"


Person::Person()
{
  name_       = "";
  age_        = 0;
  speciality_ = "";
}

Person::Person(const std::string name, const int age
             , const std::string speciality) noexcept
{
  name_       = name;     
  age_        = age;      
  speciality_ = speciality;
}

Person* Person::getNewPerson(const std::string name, const int age
                                  , const std::string speciality) noexcept
{
  return new Person(name, age, speciality);
}

std::string Person::getName() const noexcept
{
  return name_;
}

std::size_t Person::getAge() const noexcept
{
  return age_;
}

std::string Person::getSpeciality() const noexcept
{
  return speciality_;
}

void Person::setName(const std::string name) noexcept
{
  name_ = name;
}

void Person::setAge(const std::size_t age) noexcept
{
  age_ = age;
}

void Person::setSpeciality(const std::string speciality) noexcept
{
  speciality_ = speciality;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
  os << "Name " << obj.name_ << "; Age " << obj.age_
     << "; Speciality " << obj.speciality_ << "\n";

  return os;
}

bool operator<(const Person& left, const Person& right)
{
  return left.name_       < right.name_
      && left.age_        < right.age_
      && left.speciality_ < right.speciality_;
}

bool operator>(const Person& left, const Person& right)
{
  return left.name_       > right.name_
      && left.age_        > right.age_
      && left.speciality_ > right.speciality_;
}
