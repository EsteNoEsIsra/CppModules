#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int main( void )
{
    
    FragTrap a;
    FragTrap b("paco");
    
    a.attack("some other robot");
	a.takeDamage(10);
    a.highFivesGuys();
	a.takeDamage(100);
	
    a.beRepaired(50);

    b.takeDamage(90);
    b.beRepaired(20);
    b.takeDamage(30);
    b.beRepaired(30);

    b.highFivesGuys();

    return 0;
}