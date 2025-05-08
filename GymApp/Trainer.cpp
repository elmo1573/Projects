// Trainer.cpp

#include "Trainer.hpp"

Trainer::Trainer(std::string _name, int _age, std::string _gender, int _rate, std::string _charges)
    : name(_name), age(_age), gender(_gender), rating(_rate), charges(_charges) {}

std::string Trainer::getName() const { return name; }
int Trainer::getAge() const { return age; }
std::string Trainer::getGender() const { return gender; }
int Trainer::getRating() const { return rating; }
std::string Trainer::getCharges() const { return charges; }

void Trainer::setName(std::string name) { this->name = name; }
void Trainer::setAge(int age) { this->age = age; }
void Trainer::setGender(std::string gender) { this->gender = gender; }
void Trainer::setRating(int rating) { this->rating = rating; }
void Trainer::setCharges(std::string charges) { this->charges = charges; }

std::ostream &operator<<(std::ostream &os, const Trainer &trainer)
{
    os << "Name: " << trainer.name << std::endl;
    os << "Gender: " << trainer.gender << std::endl;
    os << "Rating: " << trainer.rating << std::endl;
    os << "Cost: " << trainer.charges << std::endl;
    return os;
}
