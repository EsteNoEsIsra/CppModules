#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
#pragma once
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &to_copy);
        WrongAnimal &operator=(const WrongAnimal &original);
        ~WrongAnimal();


        WrongAnimal(const std::string  &_type);
        std::string getType() const ;
        void makeSound() const ;
};
#endif