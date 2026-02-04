#include "Zombie.hpp"

Zombie Zombie::newZombie(std::string name)
{
    Zombie z;

    z.setName(name);
    return z;
}