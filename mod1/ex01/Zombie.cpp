#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << getName();
    std::cout << ": BraiiiiiiinnnzzzZ.."  << std::endl;   
}

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string name)
{
    setName(name);
}

Zombie::~Zombie()
{
    if (getName().empty())
        std::cout << "Zombie destroyed" << std::endl;
    else
        std::cout  << getName() << " is dead  D:" << std::endl;
}

void Zombie::setName(std::string _name)
{
    this->name = _name;
}
