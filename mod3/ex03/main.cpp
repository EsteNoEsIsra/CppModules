#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

int main( void )
{
    
  	DiamondTrap a;
		DiamondTrap b("Dia");
		DiamondTrap c(a);

		
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();

    return 0;
}