#include <iostream>
#include "Fixed.h"
#include "Point.h"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a;
	Point	b(13, 10);
	Point	c(0, 10);
	Point	p(2, 5);

	std::cout << "point a = " << a << std::endl;
	std::cout << "point b = " << b << std::endl;
	std::cout << "point c = " << c << std::endl;
	std::cout << "point p = " << p << std::endl;
	std::cout << "point p is inside the triangle = ";
    
    if (bsp(a,b,c,p))
    {
        std::cout << "true" << std::endl;
    }
    else 
    {
        std::cout << "false" << std::endl;
    }
	return (0);
}