#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
    public:

        // ortodox canonical form  {
        ClapTrap();
        ClapTrap(const ClapTrap &to_copy);
        ClapTrap &operator=(const ClapTrap &original);
        ~ClapTrap();
        //}
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRapaired(unsigned int amount);
        
    private:
        std::string Name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif