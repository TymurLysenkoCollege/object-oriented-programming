#pragma once

#include <string>

class Person
{
  public:

    Person();
    Person(const std::string, const int, const std::string) noexcept;
    
    static Person* getNewPerson(const std::string, const int
                                     , const std::string) noexcept;

    inline std::string getName()       const noexcept;
    inline std::size_t getAge()        const noexcept;
    inline std::string getSpeciality() const noexcept;

    inline void setName(const std::string)       noexcept;
    inline void setAge(const std::size_t)        noexcept;
    inline void setSpeciality(const std::string) noexcept;
    
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend inline bool operator<(const Person&, const Person&);
    friend inline bool operator>(const Person&, const Person&);

    ~Person() = default;

  private:

    std::string name_;
    std::string speciality_;

    std::size_t age_;
};

