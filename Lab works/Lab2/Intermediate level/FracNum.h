#pragma once
#include <string>

class FracNum
{
  public:
    
    
    FracNum();
    FracNum(std::string, std::string);


    void setNumerator(std::string);
    void setDenominator(std::string);

    std::string getNumerator() const noexcept;
    std::string getDenominator() const noexcept;


    FracNum& add(const FracNum*, const FracNum*) const;

    
    ~FracNum() = default;


  private:

    std::string numerator_;
    std::string denominator_;
};

