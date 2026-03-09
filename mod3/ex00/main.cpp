#include "ClapTrap.h"

int main( void )
{
    
    ClapTrap a;
	ClapTrap b("Juan");
    ClapTrap c("Pepe");

    a.attack("some other robot");
	a.takeDamage(1);
    //a.takeDamage(9);
	a.beRepaired(5);
    
    a.takeDamage(10);
	a.beRepaired(5);

    c.takeDamage(9);
    c.beRepaired(2);
    c.takeDamage(3);
    b.beRepaired(3);
    
    return 0;
}