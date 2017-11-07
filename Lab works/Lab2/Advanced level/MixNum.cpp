#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include "MixNum.h"

MixNum::MixNum() : base_(0), fraction_() { }

MixNum::MixNum(int base, unsigned int numerator, unsigned int denominator)
  : base_(base), fraction_()
{
  fraction_.setNumerator(numerator);
  fraction_.setDenominator(denominator);
}

MixNum& MixNum::operator=(const MixNum& mixFraction)
{
  this->setBase(mixFraction.getBase());
  this->setFractionPart(mixFraction.getFractionPart());

  return *this;
}

MixNum MixNum::add(MixNum* left, MixNum* right)
{
  FracNum* leftFrac =
    new FracNum(
                  (left->getBase() * left->getDenominator()) + left->getNumerator()
                 , left->getDenominator()
               );

  FracNum* rightFrac =
    new FracNum(
                  (right->getBase() * right->getDenominator()) + right->getNumerator()
                 , right->getDenominator()
               );

  FracNum sum = FracNum::add(leftFrac, rightFrac);

  MixNum result = MixNum(  sum.ExtractBase()
                         , sum.ExtractNumerator()
                         , sum.getDenominator());

  delete leftFrac;
  delete rightFrac;

  return result;
}

MixNum MixNum::subtract(const MixNum& left, const MixNum& right)
{
  FracNum leftFrac =
    FracNum(
              (left.getBase() * left.getDenominator()) + left.getNumerator()
             , left.getDenominator()
           );

  FracNum rightFrac =
    FracNum(
              (right.getBase() * right.getDenominator()) + right.getNumerator()
             , right.getDenominator()
           );

  FracNum diff = FracNum::subtract(leftFrac, rightFrac);

  MixNum result = MixNum(  diff.ExtractBase()
                         , diff.ExtractNumerator(), diff.getDenominator());

  return result;
}

MixNum MixNum::multiply(const MixNum& left, const MixNum& right)
{
  FracNum leftFrac =
    FracNum(
              (left.getBase() * left.getDenominator()) + left.getNumerator()
             , left.getDenominator()
           );

  FracNum rightFrac =
    FracNum(
              (right.getBase() * right.getDenominator()) + right.getNumerator()
             , right.getDenominator()
           );

  FracNum product = FracNum::mulitply(leftFrac, rightFrac);


  MixNum result = MixNum(  product.ExtractBase()
                         , product.ExtractNumerator()
                         , product.getDenominator());

  return result;
}

MixNum MixNum::divide(const MixNum& left, const MixNum& right)
{
  FracNum leftFrac =
    FracNum(
              (left.getBase() * left.getDenominator()) + left.getNumerator()
             , left.getDenominator()
           );

  FracNum rightFrac =
    FracNum(
              (right.getBase() * right.getDenominator()) + right.getNumerator()
             , right.getDenominator()
           );

  FracNum product = FracNum::divide(leftFrac, rightFrac);


  MixNum result = MixNum(  product.ExtractBase()
                         , product.ExtractNumerator()
                         , product.getDenominator());

  return result;
}

void MixNum::show(MixNum mixFraction)
{
  FracNum resultFrac = mixFraction.toFracNum();

  long long int greatestCommonDivisor = resultFrac.greatestCommonDivisor();
  resultFrac = FracNum(  resultFrac.getNumerator()   / greatestCommonDivisor
                       , resultFrac.getDenominator() / greatestCommonDivisor);

  std::cout << resultFrac.ExtractBase() << "|"
            << resultFrac.ExtractNumerator() << "/"
            << resultFrac.getDenominator();
}

void MixNum::setBase(const long long int base)
{
  base_ = base;
}

void MixNum::setFractionPart(const FracNum fraction)
{
  fraction_ = fraction;
}

void MixNum::setNumerator(const long long int numerator)
{
  fraction_.setNumerator(numerator);
}

void MixNum::setDenominator(const long long int denominator)
{
  fraction_.setDenominator(denominator);
}

const long long int MixNum::getBase() const noexcept
{
  return base_;
}

const FracNum MixNum::getFractionPart() const noexcept
{
  return this->fraction_;
}

const long long int MixNum::getNumerator() const noexcept
{
  return fraction_.getNumerator();
}

const long long int MixNum::getDenominator() const noexcept
{
  return fraction_.getDenominator();
}

const FracNum MixNum::toFracNum() const noexcept
{
  return FracNum(
                  (this->getBase() * this->getDenominator()) + this->getNumerator()
                 , this->getDenominator()
                );
}
