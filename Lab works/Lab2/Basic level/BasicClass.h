#pragma once

class BasicClass
{
  public:

    BasicClass();
    BasicClass(double, double, double);

    double func() const noexcept;


    void setx(double);
    void sety(double);
    void setz(double);


    ~BasicClass() = default;


  private:

    double x_;
    double y_;
    double z_;
};

