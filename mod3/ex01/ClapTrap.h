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
        ClapTrap(std::string _name);


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif