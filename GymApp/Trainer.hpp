// Trainer.hpp

#ifndef TRAINER_HPP
#define TRAINER_HPP

#include <string>
#include <iostream>

class Trainer
{
private:
    std::string name, gender, charges;
    int age, rating;

public:
    Trainer() {}
    Trainer(std::string _name, int _age, std::string _gender, int _rate, std::string _charges);

    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    int getRating() const;
    std::string getCharges() const;

    void setName(std::string name);
    void setAge(int age);
    void setGender(std::string gender);
    void setRating(int rating);
    void setCharges(std::string charges);

    friend std::ostream &operator<<(std::ostream &os, const Trainer &trainer);
};

#endif // TRAINER_HPP
