#pragma once

class FracNum
{
  public:
        
    FracNum();
    FracNum(double, double);


    void setNumerator  (const double);
    void setDenominator(const double);

    const double getNumerator  () const noexcept;
    const double getDenominator() const noexcept;


    static void show(FracNum);


    FracNum& operator=(const FracNum&);

    
    static FracNum& add     (FracNum*, FracNum*);
    static FracNum& subtract(FracNum&, FracNum&);
    

    ~FracNum() = default;


  private:

    long long int numerator_;
    long long int denominator_;


    double greatestCommonDivisor() const;
};
