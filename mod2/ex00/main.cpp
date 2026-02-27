#include "Fixed.hpp"


int main(void)
{
	// DEFAULT CONSTRUCTOR
	Fixed a;
	// COPY CONSTRUCTOR
	Fixed b(a);
	// DEFAULT CONSTRUCTOR
	Fixed c;

	// COPY ASSIGNMENT OPERATOR OVERLOAD
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}