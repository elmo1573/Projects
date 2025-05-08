// DailyRoutine.hpp

#ifndef DAILYROUTINE_HPP
#define DAILYROUTINE_HPP

#include <iostream>
#include "Legs.cpp"
#include "Chest.cpp"
#include "Arms.cpp"
#include "Shoulder.cpp"
#include "Back.cpp"
#include "BMI.cpp"
#include "Nutrition.cpp"

class DailyRoutine : public LegsExercise, public ChestWorkout, public Arms, public ShoulderBack
{

public:
    void showRoutine();
};

#endif // DAILYROUTINE_HPP
