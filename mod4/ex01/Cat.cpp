#include "Cat.h"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor" << std::endl;
    brain = new Brain();
}
Cat::Cat(const std::string &_type) : Animal(_type)
{
    std::cout << "Cat consttructor" << std::endl;
    brain = new Brain();
}
Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
    // std::cout << "Cat copy Constructor" << std::endl;
    brain = new Brain(*to_copy.brain);
}

Cat &Cat::operator=(const Cat &original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        delete brain;
        brain = new Brain(*original.brain);
    }
    // std::cout << "Cat copy operand Constructor" << std::endl;
    return *this;
}


Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau Miau Miau Miau Miau Miau" << std::endl;
}

Brain *Cat::getBrain() const
{
    return brain;
}