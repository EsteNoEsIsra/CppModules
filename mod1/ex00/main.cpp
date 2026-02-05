#include "Zombie.hpp"
#include "Zombie.h"

int main()
{
    Zombie* zombie1 = newZombie("JAN_Zombie");
    zombie1->announce();
    delete zombie1;
    
    randomChump("krillin_Zombie");

    return 0;
}