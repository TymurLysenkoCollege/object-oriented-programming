#pragma once
#include "person.h"

class Manager
{
  public:
    
    Manager() noexcept;

    inline void storePerson(Person*);

    inline const std::size_t size() const noexcept;
    inline Person** begin() const noexcept;
    inline Person** end()   const noexcept;

    void outputPeople() const;

    inline       Person*& operator[] (std::size_t idx);
    inline const Person*& operator[] (const std::size_t idx) const;

    ~Manager();

  private:

    void allocatePlace(std::size_t);

    Person**    people_;
    std::size_t size_;
    std::size_t capacity_;
};

