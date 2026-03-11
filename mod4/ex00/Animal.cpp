#include "Animal.h"

Animal::Animal() : type("Animal")
{
    std::cout << "Default animal Constructor" << std::endl;
}

Animal::Animal(const std::string  &_type) : type(_type)
{
    std::cout << "animal Constructor" << std::endl;
}

Animal::Animal(const Animal &to_copy) : type(to_copy.type)
{

}
Animal &Animal::operator=(const Animal &original)
{
    if (this != &original)
        *this = original;
    return *this;
}

Animal::~Animal()
{
    std::cout << "animal Destructor" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const 
{
    return (this->type);
}