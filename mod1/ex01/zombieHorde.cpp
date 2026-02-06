#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    if(N <= 0)
    {
        std::cout << " N cant be less than 1" << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N ; i++)
    {
        std::ostringstream oss;
        oss << name << "_" << i;
        horde[i].setName(oss.str());
    }
    return horde;
}