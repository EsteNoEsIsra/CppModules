#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

int main( void )
{
    /*
  	DiamondTrap a;
		DiamondTrap b("Dia");
		DiamondTrap c(a);

		
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
    */

    std::cout << "---- Default constructor ----" << std::endl;
    DiamondTrap a;

    std::cout << "\n---- Constructor with name ----" << std::endl;
    DiamondTrap b("Alex");

    std::cout << "\n---- Attack test ----" << std::endl;
    b.attack("enemy");

    std::cout << "\n---- whoAmI test ----" << std::endl;
    b.whoAmI();

    std::cout << "\n---- Copy constructor ----" << std::endl;
    DiamondTrap c(b);
    c.whoAmI();

    std::cout << "\n---- Assignment operator ----" << std::endl;
    DiamondTrap d;
    d = b;
    d.whoAmI();

    std::cout << "\n---- End of program ----" << std::endl;



    return 0;
}