#include "stdafx.h"
#include "Manager.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

Manager::Manager() noexcept
{
  capacity_ = 1;
  size_     = 0;
  people_   = nullptr;
  allocatePlace(capacity_);
}

inline void Manager::storePerson(Person* personElement)
{
  if (size_ >= capacity_)
  {
    capacity_ *= 2;
    allocatePlace(capacity_);
  }

  people_[size_++] = personElement;
}

inline const std::size_t Manager::size() const noexcept
{
  return size_;
}

inline Person** Manager::begin() const noexcept
{
  return people_;
}

inline Person** Manager::end() const noexcept
{
  return (people_ + size_);
}

void Manager::outputPeople(unsigned int sortBy) const
{
  Manager sortedManager;

  for (unsigned int i = 0; i < size_; ++i)
  {
    sortedManager.storePerson(people_[i]);
  }

  std::function<bool(const Person*, const Person*)> sortFunction;

  switch (sortBy)
  {
    case 1 :
    {
      sortFunction = [](const Person* left, const Person* right)
      {
        return left->getName() < right->getName();
      };

      break;
    }

    case 2 :
    {
      sortFunction = [](const Person* left, const Person* right)
      {
        return left->getAge() < right->getAge();
      };

      break;
    }

    case 3 :
    {
      sortFunction = [](const Person* left, const Person* right)
      {
        return left->getSpeciality() < right->getSpeciality();
      };

      break;
    }

    default:
    {
      sortFunction = [](const Person* left, const Person* right)
      {
        return *left < *right;
      };

      break;
    }
  }

  std::sort(sortedManager.begin(), sortedManager.end(), sortFunction);

  for (unsigned int i = 0; i < size_; ++i)
  {
    std::cout << "Manager[" << i << "] = " << *(sortedManager[i]);
  }
}

inline Person*& Manager::operator[](std::size_t idx)
{
  if (idx < size_)
  {
    return people_[idx];
  }
  
  throw std::out_of_range("There is no person with this index");
}

inline const Person*& Manager::operator[](const std::size_t idx) const
{
  if (idx < size_)
  {
    return const_cast<const Person*&>(people_[idx]);
  }

  throw std::out_of_range("There is no person with this index");
}

Manager::~Manager()
{
  delete[] people_;
}

void Manager::allocatePlace(std::size_t size)
{
  Person** reallocedPeople = new Person*[size];

  for (std::size_t i = 0; i < size_; ++i)
  {
    reallocedPeople[i] = people_[i];
  }

  if (!people_)
  {
    delete[] people_;
  }

  people_ = reallocedPeople;
}
