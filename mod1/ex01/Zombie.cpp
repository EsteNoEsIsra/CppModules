#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << getName();
    std::cout << ": BraiiiiiiinnnzzzZ.."  << std::endl;   
}

Zombie::Zombie()
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string name)
{
    setName(name);
}


Zombie::~Zombie()
{
    std::cout  << getName() << " is dead  D:" << std::endl;
}

void Zombie::setName(std::string _name)
{
    this->name = _name;
}
