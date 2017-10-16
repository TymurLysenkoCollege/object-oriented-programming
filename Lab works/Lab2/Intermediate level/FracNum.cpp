#include "stdafx.h"
#include "FracNum.h"

FracNum::FracNum() : numerator_(""), denominator_("")
{
}

FracNum::FracNum(std::string numerator, std::string denominator) : 
  numerator_(numerator), denominator_(denominator)
{

}

void FracNum::setNumerator(std::string numerator)
{
  numerator_ = numerator;
}

void FracNum::setDenominator(std::string denominator)
{
  denominator_ = denominator;
}

std::string FracNum::getNumerator() const noexcept
{
  return numerator_;
}

std::string FracNum::getDenominator() const noexcept
{
  return denominator_;
}

FracNum& FracNum::add(const FracNum* left, const FracNum* right) const
{
  return 
}
