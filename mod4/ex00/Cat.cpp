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

}

Cat &Cat::operator=(const Cat &original)
{
    if (this != &original)
        *this = original;
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