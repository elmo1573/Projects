// Legs.hpp

#ifndef LEGS_HPP
#define LEGS_HPP

#include <iostream>

class Legs
{
public:
    virtual void basicWorkout() = 0;
    virtual void intermediateWorkout() = 0;
    virtual void advancedWorkout() = 0;
};

class LegsExercise : public Legs
{
public:
    void basicWorkout() override;
    void intermediateWorkout() override;
    void advancedWorkout() override;
};

#endif // LEGS_HPP
