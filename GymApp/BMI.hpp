// BMI.hpp

#ifndef BMI_HPP
#define BMI_HPP

class BMI
{
private:
    double height;
    double weight;
    double bmi;

public:
    BMI();

    void set(double height, double weight);
    void calcBMI();
    double getBMI();
};

#endif // BMI_HPP
