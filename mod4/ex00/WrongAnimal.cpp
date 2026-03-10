#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{

}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy) : type(to_copy.type)
{

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
     if (this != &original)
    *this = original;
}

WrongAnimal::~WrongAnimal()
{

}

void WrongAnimal::makeSound() const 
{
    std::cout << "wrong animal sound" << std::endl;
}