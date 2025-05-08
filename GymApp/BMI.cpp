
#include <iostream>
#include "BMI.hpp"
using namespace std;
// BMI.cpp

#include "BMI.hpp"

BMI::BMI()
{
}

void BMI::set(double height, double weight)
{
    this->height = height;
    this->weight = weight;
}

void BMI::calcBMI()
{
    bmi = weight / (height * height);
}

double BMI::getBMI()
{
    return bmi;
}
