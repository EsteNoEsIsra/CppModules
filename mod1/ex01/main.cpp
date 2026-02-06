#include "Zombie.hpp"
#include "Zombie.h"

int main( void)
{
    int N = 5;

    Zombie* zombie = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++)
        zombie[i].announce();
    
    delete[] zombie;
    
    return 0;
}