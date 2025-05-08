// Chest.hpp

#ifndef CHEST_HPP
#define CHEST_HPP

#include <iostream>

class Chest
{
public:
    virtual void basic() = 0;
    virtual void intermediate() = 0;
    virtual void advanced() = 0;
};

class ChestWorkout : public Chest
{
public:
    void basic() override;
    void intermediate() override;
    void advanced() override;
};

#endif // CHEST_HPP
