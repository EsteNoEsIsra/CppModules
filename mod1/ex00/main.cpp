#include "Zombie.hpp"
#include "Zombie.h"

int main()
{
    Zombie* zombie1 = newZombie("JAN_Zombie");
    zombie1->announce();

//    Zombie* zombie2 = newZombie("Reservo_y_no_muero");

//    zombie2->announce();


    delete zombie1;
    //delete zombie2;

    randomChump("krillin_Zombie");



    randomChump("Paco_Zombie");

    return 0;
}
