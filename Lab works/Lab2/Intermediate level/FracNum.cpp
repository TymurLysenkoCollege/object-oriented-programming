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

void FracNum::show(FracNum fraction)
{
  std::cout << (fraction.numerator_   / fraction.greatestCommonDivisor()) << "/"
            << (fraction.denominator_ / fraction.greatestCommonDivisor());
}

FracNum& FracNum::operator=(const FracNum& fraction)
{
  this->numerator_   = fraction.numerator_;
  this->denominator_ = fraction.denominator_;

  return *this;
}

FracNum& FracNum::add(FracNum* left, FracNum* right)
{
  return FracNum(  (left->getNumerator() * right->getDenominator()) + (right->getNumerator() * left->getDenominator())
                 , left->getDenominator() * right->getDenominator() );
}

FracNum& FracNum::subtract(FracNum& left, FracNum& right)
{
  return FracNum(  (left.getNumerator() * right.getDenominator()) - (right.getNumerator() * left.getDenominator())
                 , left.getDenominator() * right.getDenominator() );
}

double FracNum::greatestCommonDivisor() const
{
  double numerator   = std::abs(numerator_);
  double denominator = std::abs(denominator_);

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
