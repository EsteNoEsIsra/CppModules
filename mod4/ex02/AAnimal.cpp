#include "AAnimal.h"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "Default AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const std::string  &_type) : type(_type)
{
    std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &to_copy) : type(to_copy.type)
{
   // std::cout << "animal copy Constructor" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &original)
{
    if (this != &original)
        *this = original;
    // std::cout << "animal copy operand Constructor" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "animal Destructor" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const 
{
    return (this->type);
}