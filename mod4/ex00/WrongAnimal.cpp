#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default wrong animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string  &_type) : type(_type)
{
    std::cout << "wrong animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy) : type(to_copy.type)
{

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
    if (this != &original)
        *this = original;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "wrong animal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return (this->type);
}