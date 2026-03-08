#include "ClapTrap.h"
#include "ScavTrap.h"

int main( void )
{
    
    ScavTrap a;
    ScavTrap b("paco");
    
    a.attack("some other robot");
	a.takeDamage(10);
    a.guardGate();
	a.takeDamage(100);
	
    a.beRepaired(50);

    b.takeDamage(90);
    b.beRepaired(20);
    b.takeDamage(30);
    b.beRepaired(30);

    b.guardGate();

    return 0;
}