#pragma once
#include <string>
#include <ctime>

class Vorker
{

  public:

    Vorker();
    Vorker(int, int, std::string, std::string, std::string, std::time_t);

    int         getId        () const noexcept;
    int         getSallary   () const noexcept;
    std::string getFullName  () const noexcept;
    std::string getDepartment() const noexcept;
    std::string getPosition  () const noexcept;
    std::time_t getEmpDate   () const noexcept;
    std::tm     getEmpDateTM () const noexcept;


    void setId        (int);
    void setSallary   (int);
    void setFullName  (std::string);
    void setDepartment(std::string);
    void setPosition  (std::string);
    void setEmpDate   (std::time_t);

    std::time_t countWorkExperienceInDays() const noexcept;

    friend std::ostream& operator << (std::ostream&, const Vorker&);
    Vorker&              operator += (const Vorker&);

    ~Vorker() = default;

  private:

    int         _id;
    int         _sallary;
    std::string _fullName;
    std::string _department;
    std::string _position;
    std::time_t _empDate;

};

