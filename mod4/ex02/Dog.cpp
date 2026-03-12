#include "Dog.h"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Default Dog Constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const std::string &_type) : AAnimal(_type)
{
    std::cout << "Dog Constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &to_copy) : AAnimal(to_copy)
{
    // std::cout << "Dog copy Constructor" << std::endl;
    brain = new Brain (*to_copy.brain);
}

Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
    {
        AAnimal::operator=(original);
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