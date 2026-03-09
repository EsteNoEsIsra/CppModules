#include "ClapTrap.h"
#include "ScavTrap.h"

int main( void )
{
    
    ScavTrap a;
    ScavTrap b("paco");

    //a = b;
    a.attack("some other robot");
	a.takeDamage(10);
    a.guardGate();
	a.takeDamage(100);
	
    a.beRepaired(50);
    b.takeDamage(90);
    b.attack("HAL");
    

    b.guardGate();

    return 0;
}