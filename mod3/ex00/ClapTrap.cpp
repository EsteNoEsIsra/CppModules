#include "ClapTrap.h"


ClapTrap::ClapTrap() : Name(Name)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->Name = "default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
    std::cout << "ClapTrap copy Constructor called" << std::endl;
    *this = to_copy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    
    this->Name = original.Name;
    this->hitPoints = original.hitPoints;
    this->energyPoints = original.energyPoints;
    this->attackDamage = original.attackDamage;
    
    std::cout << "ClapTrap copy from the original" << std::endl;

    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints != 0 || this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attacks "  << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else 
        std::cout << "No energy points left" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{   
    if (this->hitPoints > (int)amount )
        std::cout << "ClapTrap " << this->Name << " recives " << amount << " points of damage!" << std::endl;
    else if ((int)amount > this->hitPoints || this->hitPoints == 0)
        std::cout << "ClapTrap " << this->Name << " Destroyed" << std::endl;
}
void ClapTrap::beRapaired(unsigned int amount)
{
    if (this->energyPoints != 0 || this->energyPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints--;
    }
    else 
        std::cout << "No energy points left" << std::endl;
    
}