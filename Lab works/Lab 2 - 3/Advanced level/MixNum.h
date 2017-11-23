#pragma once
#include "../Intermediate level/FracNum.h"

class MixNum
{
  public:

    MixNum();
    MixNum(int, unsigned int, unsigned int);


    MixNum& operator=(const MixNum&);


    static MixNum add     (MixNum*, MixNum*);
    static MixNum subtract(const MixNum&, const MixNum&);
    static MixNum multiply(const MixNum&, const MixNum&);
    static MixNum divide  (const MixNum&, const MixNum&);


    static void show(MixNum);


    void setBase        (const long long int);
    void setFractionPart(const FracNum);
    void setNumerator   (const long long int);
    void setDenominator (const long long int);


    const long long int getBase         () const noexcept;
    const FracNum       getFractionPart () const noexcept;
    const long long int getNumerator    () const noexcept;
    const long long int getDenominator  () const noexcept;
    const FracNum       toFracNum       () const noexcept;


    ~MixNum() = default;


  private:

    FracNum fraction_;
    int     base_;
};
