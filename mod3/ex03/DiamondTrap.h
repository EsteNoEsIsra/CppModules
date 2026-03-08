#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#pragma once

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &to_copy);
        DiamondTrap &operator=(const DiamondTrap &original);
        ~DiamondTrap();


        DiamondTrap(std::string _name);
        void whoAmI();
        void attack(const std::string& target); 
    private:
        std::string name;
};

#endif