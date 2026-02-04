#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << getName();
    std::cout << ": BraiiiiiiinnnzzzZ.."  << std::endl;   
}

void Zombie::setName(std::string _name)
{
    this->name = _name;
}
