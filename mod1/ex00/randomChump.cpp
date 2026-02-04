#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
    Zombie random = newZombie(name);
    random.announce();

}