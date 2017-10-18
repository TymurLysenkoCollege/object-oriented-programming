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


    void show();


    FracNum& operator=(const FracNum&);

    
    static const FracNum& add     (const FracNum*, const FracNum*);
    static const FracNum& subtract(const FracNum&, const FracNum&);
    

    ~FracNum() = default;


  private:

    double numerator_;
    double denominator_;


    double greatestCommonDivisor() const;
};
