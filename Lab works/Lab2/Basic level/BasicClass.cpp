#include "stdafx.h"
#include "BasicClass.h"
#include <math.h>

BasicClass::BasicClass() : x_(0), y_(0), z_(0)
{
}

BasicClass::BasicClass(double x, double y, double z) : x_(x), y_(y), z_(z)
{
}

double BasicClass::func() const noexcept
{
  return (
          (
           ( pow(x_, y_ + 1) + exp(y_ - 1  )) /
           ( 1 + (x_ * fabs(y_ - tan(z_))) )
          ) *
          (1 + fabs(y_ - x_))
         ) +
         (pow(fabs(y_ - x_), 2) / 2) -
         (pow(fabs(y_ - x_), 3) / 3);
}

void BasicClass::setx(double x)
{
  x_ = x;
}

void BasicClass::sety(double y)
{
  y_ = y;
}

void BasicClass::setz(double z)
{
  z_ = z;
}
