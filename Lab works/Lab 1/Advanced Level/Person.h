#pragma once

#include <string>

class Person
{
  public:

    Person();
    Person(const std::string, const int, const std::string) noexcept;
    
    static Person* getNewPerson(const std::string, const int
                                     , const std::string) noexcept;

    std::string getName()       const noexcept;
    std::size_t getAge()        const noexcept;
    std::string getSpeciality() const noexcept;

    void setName(const std::string)       noexcept;
    void setAge(const std::size_t)        noexcept;
    void setSpeciality(const std::string) noexcept;
    
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend bool operator<(const Person&, const Person&);
    friend bool operator>(const Person&, const Person&);

    ~Person() = default;

  private:

    std::string name_;
    std::string speciality_;

    std::size_t age_;
};

