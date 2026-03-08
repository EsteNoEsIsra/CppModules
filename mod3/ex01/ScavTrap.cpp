#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap("default")
{
    std::cout << "ScavTrap default Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap (_name)
{
    std::cout << "ScavTrap " << name << " Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy)
{
    std::cout << "ScavTrap copy Constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
    std::cout << "ScavTrap operator copy from the original" << std::endl;

   ClapTrap::operator=(original);

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
     if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks "  << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (this->energyPoints <= 0)
        std::cout << "ScavTrap " << this->name << " cant attack "  << target << " no energy left" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " cant attack because is destroyed" << std::endl;
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
//   if (this->hitPoints > (int)amount)
//     {
//         std::cout << "ScavTrap " << this->name << " recives " << amount << " points of damage!" << std::endl;
//         this->hitPoints -= amount;
        
//     }
//     else if ((int)amount >= this->hitPoints)
//     {
//         std::cout << "ScavTrap " << this->name << " is Destroyed" << std::endl;
//         this->hitPoints = 0;
//     }
// }
// void ScavTrap::beRepaired(unsigned int amount)
// {
//  if (this->energyPoints > 0 && this->hitPoints > 0)
//     {
//         this->hitPoints += amount;
//         std::cout << "ScavTrap " << this->name << " repairs " << amount << " hit points " << std::endl;
//         this->energyPoints--;
//     }
//     else if (this->energyPoints <= 0)
//         std::cout << "ScavTrap " << this->name << " cant be reapired  no energy left" << std::endl;
//     else
//         std::cout << "ScavTrap " << this->name << " cant be reapired  because is destoyed" << std::endl;
// }

void ScavTrap::guardGate()
{
    if (this->hitPoints > 0)
        std::cout << "ScavTrap " << this->name << " is in Gate keeper mode" << std::endl;
    else 
        std::cout << "ScavTrap " << this->name << " cant be in Gate Keeper mode because is destroyed " << std::endl;
}