#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#pragma once
#include "ClapTrap.h"

class ScavTrap : public  ClapTrap
{
    public:
          // ortodox canonical form  {
        ScavTrap();
        ScavTrap(const ScavTrap &to_copy);
        ScavTrap &operator=(const ScavTrap &original);
        ~ScavTrap();
        //}

        ScavTrap(std::string _name);
        void attack(const std::string& target);
        void guardGate();
    private: 
};

#endif