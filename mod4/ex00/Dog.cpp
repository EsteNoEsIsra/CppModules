#include "Dog.h"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog Constructor" << std::endl;
}

Dog::Dog(const std::string &_type) : Animal(_type)
{
    std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{

}

Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
        *this = original;
    return *this;
}


Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Guau Guau Guau Guau Guau Guau Guau " << std::endl;
}