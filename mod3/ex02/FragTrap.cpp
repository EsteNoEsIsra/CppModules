#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap("default")
{
    std::cout << "FragTrap default Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap (_name)
{
    std::cout << "FragTrap " << name << " Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &to_copy) : ClapTrap(to_copy)
{
    std::cout << "FragTrap copy Constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &original)
{
    std::cout << "FragTrap operator copy from the original" << std::endl;

   ClapTrap::operator=(original);

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}


void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << name << " says: HighFivesGuys  :D" << std::endl;
}
/*
void FragTrap::attack(const std::string& target)
{
     if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks "  << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (this->energyPoints <= 0)
        std::cout << "FragTrap " << this->name << " cant attack "  << target << " no energy left" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " cant attack because is destroyed" << std::endl;
}
*/