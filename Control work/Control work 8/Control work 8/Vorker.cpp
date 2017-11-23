#include "stdafx.h"
#include "Vorker.h"
#include <ctime>
#include <time.h>
#pragma warning(disable : 4996)

Vorker::Vorker() :
    _id (0), _sallary(0), _fullName("")
  , _department(""), _position(""), _empDate()
{ }

Vorker::Vorker(  int id, int sallary, std::string fullName
               , std::string department, std::string position
               , std::time_t empDate) :
  _id(id), _sallary(sallary), _fullName(fullName)
  , _department(department), _position(position), _empDate(empDate)
{ }

int Vorker::getId() const noexcept
{
  return _id;
}

int Vorker::getSallary() const noexcept
{
  return _sallary;
}

std::time_t Vorker::getEmpDate() const noexcept
{
  return _empDate;
}

std::tm Vorker::getEmpDateTM() const noexcept
{
  return *std::localtime(&_empDate);;
}

std::string Vorker::getFullName() const noexcept
{
  return _fullName;
}

std::string Vorker::getDepartment() const noexcept
{
  return _department;
}

std::string Vorker::getPosition() const noexcept
{
  return _position;
}

void Vorker::setId(int id)
{
  _id = id;
}

void Vorker::setSallary(int sallary)
{
  _sallary = sallary;
}

void Vorker::setEmpDate(std::time_t empDate)
{
  _empDate = empDate;
}

void Vorker::setFullName(std::string fullName)
{
  _fullName = fullName;
}

void Vorker::setDepartment(std::string department)
{
  _department = department;
}

void Vorker::setPosition(std::string position)
{
  _position = position;
}

std::time_t Vorker::countWorkExperienceInDays() const noexcept
{
  return difftime(std::time(nullptr), _empDate) / 86400;
}


std::ostream& operator << (std::ostream& os, const Vorker& vorker)
{
  os << "ID = "               << vorker._id
     << "\nSallary = "        << vorker._sallary
     << "\nFull name = "      << vorker._fullName
     << "\nDepartment = "     << vorker._department
     << "\nPosition = "       << vorker._position
     << "\nEployment date = "
     << vorker.getEmpDateTM().tm_year + 1900
     << "/" << vorker.getEmpDateTM().tm_mon + 1
     << "/" << vorker.getEmpDateTM().tm_mday
     << " " << vorker.getEmpDateTM().tm_hour
     << ":" << vorker.getEmpDateTM().tm_min
     << ":" << vorker.getEmpDateTM().tm_sec
     << "\nWork experience in days = " << vorker.countWorkExperienceInDays()
     << "\n";

  return os;
}

Vorker& Vorker::operator += (const Vorker& vorker)
{
  _sallary += vorker._sallary;

  return *this;
}
