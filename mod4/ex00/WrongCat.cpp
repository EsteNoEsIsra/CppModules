
#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongAnimal")
{

}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy)
{

}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
     if (this != &original)
    *this = original;
}

WrongCat::~WrongCat()
{

}

void WrongCat::makeSound() const 
{
    std::cout << "wrong Cat sound" << std::endl;
}