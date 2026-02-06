#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{

}

void HumanB::attack()
{
    if (!this->weapon)
    {
        std::cout << this->name << " has no weapon to attack with!" << std::endl; 
        return;
    }
    else 
        std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl; 
}


HumanB::~HumanB()
{

}

Weapon* HumanB::setWeapon(Weapon weapon)
{
    this->weapon = new Weapon(weapon.getType());    

    return this->weapon;
}