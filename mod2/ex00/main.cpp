#include "Fixed.hpp"


int main(void)
{
	
	Fixed a;  // DEFAULT CONSTRUCTOR	
	Fixed b(a); // COPY CONSTRUCTOR
	Fixed c;// DEFAULT CONSTRUCTOR
	c = b;// COPY ASSIGNMENT OPERATOR OVERLOAD

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}