#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#pragma once
#include "ClapTrap.h"

class FragTrap  : virtual public ClapTrap
{
   public:
      // ortodox canonical form  {
         FragTrap();
         FragTrap(const FragTrap &to_copy);
         FragTrap &operator=(const FragTrap &original);
         ~FragTrap();
      //}

         //        void attack(const std::string& target)
         FragTrap(std::string _name);
         void highFivesGuys(void);
   private:

};

#endif