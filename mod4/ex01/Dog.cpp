#include "Dog.h"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog Constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const std::string &_type) : Animal(_type)
{
    std::cout << "Dog Constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
    // std::cout << "Dog copy Constructor" << std::endl;
    brain = new Brain (*to_copy.brain);
}

Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        delete brain;
        brain = new Brain (*original.brain);
    }
    // std::cout << "Dog copy operand Constructor" << std::endl;
    return *this;
}


Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Guau Guau Guau Guau Guau Guau Guau " << std::endl;
}


Brain *Dog::getBrain() const
{
    return brain;
}