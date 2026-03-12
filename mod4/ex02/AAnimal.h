#ifndef ANIMAL_H
# define ANIMAL_H
#pragma once
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal &to_copy);
        AAnimal &operator=(const AAnimal &original);
        virtual ~AAnimal();

        AAnimal(const std::string  &_type);
        std::string getType() const;
        virtual void makeSound() const = 0;
};
#endif