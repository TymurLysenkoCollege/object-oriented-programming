#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include "FracNum.h"

FracNum::FracNum() : numerator_(0), denominator_(1) { }

FracNum::FracNum(double numerator, double denominator)
{
  setNumerator  (numerator);
  setDenominator(denominator);
}

void FracNum::setNumerator(const double numerator)
{
  numerator_ = numerator;
}

void FracNum::setDenominator(const double denominator)
{
  if (denominator == 0)
  {
    throw std::invalid_argument("Denominator can't be 0!\n");
  }
  else
  {
    denominator_ = denominator;
  }
}

const double FracNum::getNumerator() const noexcept
{
  return numerator_;
}

const double FracNum::getDenominator() const noexcept
{
  return denominator_;
}

void FracNum::show()
{
  std::cout << this->numerator_ << "/" << this->denominator_ << " = "
            << (this->numerator_ / this->greatestCommonDivisor()) << "/"
            << (this->denominator_ / this->greatestCommonDivisor()) << "\n";
}

FracNum& FracNum::operator=(const FracNum& fraction)
{
  this->numerator_   = fraction.numerator_;
  this->denominator_ = fraction.denominator_;

  return *this;
}

const FracNum& FracNum::add(const FracNum* left, const FracNum* right)
{
  return FracNum(  (left->getNumerator() * right->getDenominator()) + (right->getNumerator() * left->getDenominator())
                 , left->getDenominator() * right->getDenominator() );
}

const FracNum& FracNum::subtract(const FracNum& left, const FracNum& right)
{
  return FracNum(  (left.getNumerator() * right.getDenominator()) - (right.getNumerator() * left.getDenominator())
                 , left.getDenominator() * right.getDenominator() );
}

double FracNum::greatestCommonDivisor() const
{
  double numerator   = numerator_;
  double denominator = denominator_;

  while (numerator != denominator)
  {
    if (numerator > denominator)
    {
      numerator -= denominator;
    }
    else
    {
      denominator -= numerator;
    }
  }

  return numerator;
}
