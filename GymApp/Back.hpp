// Back.hpp

#ifndef BACK_HPP
#define BACK_HPP

#include <iostream>

class Back
{
public:
    virtual void basic() = 0;
    virtual void intermediate() = 0;
    virtual void advanced() = 0;
};

class BackWorkout : public Back
{
public:
    void basic() override;
    void intermediate() override;
    void advanced() override;
};

#endif // BACK_HPP
