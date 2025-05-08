// MonthlyProgress.hpp

#ifndef MONTHLYPROGRESS_HPP
#define MONTHLYPROGRESS_HPP

#include <string>

class MonthlyProgress
{
private:
    double weight_day1;
    double weight_day7;
    double waist_day1;
    double waist_day7;

public:
    MonthlyProgress(double w1, double w7, double wd1, double wd7);

    std::string report() const;
};

#endif // MONTHLYPROGRESS_HPP
