#include "Cat.h"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor" << std::endl;
}
Cat::Cat(const std::string &_type) : Animal(_type)
{
    std::cout << "Cat destructor" << std::endl;
}
Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
    // std::cout << "Cat copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
    if (this != &original)
        *this = original;
    // std::cout << "Cat copy operand Constructor" << std::endl;
    return *this;
}


Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau Miau Miau Miau Miau Miau" << std::endl;
}