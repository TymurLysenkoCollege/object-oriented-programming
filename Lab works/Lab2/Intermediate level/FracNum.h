#pragma once

class FracNum
{
  public:

    FracNum();
    FracNum(long long int, long long int);


    void setNumerator  (const long long int);
    void setDenominator(const long long int);

    const long long int getNumerator  () const noexcept;
    const long long int getDenominator() const noexcept;


    static void show(FracNum);


    FracNum& operator=(const FracNum&);

    
    static FracNum add     (FracNum*, FracNum*);
    static FracNum subtract(const FracNum&, const FracNum&);
    static FracNum mulitply(const FracNum&, const FracNum&);
    static FracNum divide  (const FracNum&, const FracNum&);
    

    const long long int greatestCommonDivisor() const;
    const int           ExtractBase          () const;
    const int           ExtractNumerator     () const;


    ~FracNum() = default;


  private:

    long long int numerator_;
    long long int denominator_;
};
