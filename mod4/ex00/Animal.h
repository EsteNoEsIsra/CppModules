#ifndef ANIMAL_H
# define ANIMAL_H
#pragma once
#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &to_copy);
        Animal &operator=(const Animal &original);
        ~Animal();

        Animal(const std::string  &_type);
        virtual void makeSound() const ;
};
#endif