// MonthlyProgress.cpp

#include "MonthlyProgress.hpp"

MonthlyProgress::MonthlyProgress(double w1, double w7, double wd1, double wd7) : weight_day1(w1), weight_day7(w7), waist_day1(wd1), waist_day7(wd7) {}

std::string MonthlyProgress::report() const
{
    double weight_loss = weight_day1 - weight_day7;
    double waist_loss = waist_day1 - waist_day7;
    double weight_gain = weight_day7 - weight_day1;
    double waist_gain = waist_day7 - waist_day1;

    if (weight_loss > 0 && waist_loss > 0)
    {
        return "Great job! You lost " + std::to_string(weight_loss) + "kg of weight and " + std::to_string(waist_loss) + "cm of waist in one month!";
    }
    else if (weight_loss > 0 && waist_loss <= 0)
    {
        return "Good job! You lost " + std::to_string(weight_loss) + "kg of weight but your waist didn't change in one month!";
    }
    else if (weight_loss <= 0 && waist_loss > 0)
    {
        return "Good job! You didn't lose weight but you lost " + std::to_string(waist_loss) + "cm of waist in one month!";
    }
    else if (weight_gain > 0 && waist_gain > 0)
    {
        return "Great job! You gained " + std::to_string(weight_gain) + "kg of weight and " + std::to_string(waist_gain) + "cm of waist in one month!";
    }
    else if (weight_gain > 0 && waist_gain < 0)
    {
        return "That is not possible, you might have entered incorrect values ";
    }
    else if (waist_gain > 0 && weight_gain < 0)
    {
        return "That is not possible, you might have entered incorrect values ";
    }
    else
    {
        return "Oops! You didn't make any progress in one month. Keep trying!";
    }
}
