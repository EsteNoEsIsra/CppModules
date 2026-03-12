
#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongAnimal")
{
    std::cout << "Default wrong Cat Constructor" << std::endl;
}
WrongCat::WrongCat(const std::string &_type) : WrongAnimal(_type)
{
    std::cout << "wrong Cat destructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy)
{
    // std::cout << "Wrong cat copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
    if (this != &original)
        *this = original;
    // std::cout << "Wrong cat copy operand Constructor" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "wrong Cat destructor" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "wrong Cat sound" << std::endl;
}