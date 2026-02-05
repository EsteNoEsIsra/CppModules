#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    if(N <= 0)
    {
        std::cout << " N cant be less than 0" << std::endl;
        return NULL;
    }

    Zombie* horde[N] = new Zombie[N];
    for (int i = 0; i < N ; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}