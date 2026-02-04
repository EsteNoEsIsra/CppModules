#include "Zombie.hpp"

int main()
{
    Zombie* zombie1 = newZombie("JAN_Zombie");
    zombie1->announce();
    delete zombie1;
    
    return 0;
}