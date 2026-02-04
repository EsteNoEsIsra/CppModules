#include "Zombie.h"
#include "Zombie.hpp"

int main()
{
    Zombie* zombie1 = newZombie("HeapZombie");
    zombie1->announce();
    delete zombie1;

    return 0;
}