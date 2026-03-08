#include "ClapTrap.h"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) 
{
    this->name = _name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << name << " Constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
    std::cout << "ClapTrap copy Constructor called" << std::endl;
    *this = to_copy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    std::cout << "ClapTrap operator copy from the original" << std::endl;

    this->name = original.name;
    this->hitPoints = original.hitPoints;
    this->energyPoints = original.energyPoints;
    this->attackDamage = original.attackDamage;

    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks "  << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (this->energyPoints == 0 || this->energyPoints < 0)
        std::cout << "ClapTrap " << this->name << " cant attack "  << target << " no energy left" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " cant attack because is destroyed" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{   
    if (this->hitPoints > (int)amount)
    {
        std::cout << "ClapTrap " << this->name << " recives " << amount << " points of damage!" << std::endl;
        this->hitPoints -= amount;
        
    }
    else if ((int)amount >= this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " is Destroyed" << std::endl;
        this->hitPoints = 0;
    }
    
}
    
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " repairs " << amount << " hit points " << std::endl;
        this->energyPoints--;
    }
    else if (this->energyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " cant be reapired  no energy left" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " cant be reapired  because is destoyed" << std::endl;
}