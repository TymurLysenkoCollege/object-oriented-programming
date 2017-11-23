#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include "FracNum.h"

FracNum::FracNum() : numerator_(0), denominator_(1) { }

FracNum::FracNum(long long int numerator, long long int denominator)
{
  setNumerator  (numerator);
  setDenominator(denominator);
}

void FracNum::setNumerator(const long long int numerator)
{
  numerator_ = numerator;
}

void FracNum::setDenominator(const long long int denominator)
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

const long long int FracNum::getNumerator() const noexcept
{
  return numerator_;
}

const long long int FracNum::getDenominator() const noexcept
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

FracNum FracNum::add(FracNum* left, FracNum* right)
{
  FracNum result =
    FracNum(
             (left->getNumerator() * right->getDenominator()) + (right->getNumerator() * left->getDenominator())
            , left->getDenominator() * right->getDenominator()
           );
  
  const long long int greatestCommonDivisor = result.greatestCommonDivisor();
  
  result.setNumerator(result.getNumerator()     / greatestCommonDivisor);
  result.setDenominator(result.getDenominator() / greatestCommonDivisor);
  
  return result;
}

FracNum FracNum::subtract(const FracNum& left, const FracNum& right)
{
  FracNum result =
    FracNum(
             (left.getNumerator() * right.getDenominator()) - (right.getNumerator() * left.getDenominator())
            , left.getDenominator() * right.getDenominator()
           );
  
  const long long int greatestCommonDivisor = result.greatestCommonDivisor();
  
  result.setNumerator(result.getNumerator()     / greatestCommonDivisor);
  result.setDenominator(result.getDenominator() / greatestCommonDivisor);
  
  return result;
}

FracNum FracNum::mulitply(const FracNum& left, const FracNum& right)
{
  FracNum result =
    FracNum(  left.getNumerator()   * right.getNumerator()
            , left.getDenominator() * right.getDenominator());

  const long long int greatestCommonDivisor = result.greatestCommonDivisor();

  result.setNumerator(result.getNumerator()     / greatestCommonDivisor);
  result.setDenominator(result.getDenominator() / greatestCommonDivisor);

  return result;
}

FracNum FracNum::divide(const FracNum& left, const FracNum& right)
{
  FracNum result =
    FracNum(  left.getNumerator()   * right.getDenominator()
            , left.getDenominator() * right.getNumerator());

  const long long int greatestCommonDivisor = result.greatestCommonDivisor();

  result.setNumerator(result.getNumerator()     / greatestCommonDivisor);
  result.setDenominator(result.getDenominator() / greatestCommonDivisor);

  return result;
}

const long long int FracNum::greatestCommonDivisor() const
{
  long long int numerator   = std::abs(numerator_);
  long long int denominator = std::abs(denominator_);

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

const int FracNum::ExtractBase() const
{
  return numerator_ / std::abs(denominator_);
}

const int FracNum::ExtractNumerator() const
{
  return std::abs(numerator_ % denominator_);
}
