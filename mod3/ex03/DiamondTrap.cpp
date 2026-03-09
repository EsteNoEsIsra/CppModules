#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap("defalutD_clap_name")//,ScavTrap("defalutD_clap_Scav"), FragTrap("defalutD_clap_Frag")
{
    this->name = "defaultD";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy) : ClapTrap(to_copy)//, ScavTrap(to_copy),FragTrap(to_copy)
{
    std::cout << "DiamondTrap copy Constructor called" << std::endl;
    *this = to_copy;

}


DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name") , ScavTrap(_name), FragTrap(_name)
{
    this->name = _name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    std::cout << "DiamondTrap operator copy from the original" << std::endl;
    if(this != &original)
    {
        this->name = original.name ;
        this->hitPoints = original.hitPoints;
        this->energyPoints = original.energyPoints;
        this->attackDamage = original.attackDamage;
        ClapTrap::name = original.ClapTrap::name;
    }

    
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
    std::cout << "I am " << name << " a DiamondTrap "<< std::endl;
    std::cout << "I am " << ClapTrap::name << " from ClapTrap "<< std::endl;
}