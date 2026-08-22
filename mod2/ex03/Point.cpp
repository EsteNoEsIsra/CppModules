#include "Point.h"

Point::Point() : x(0),y(0)
{}

Point::Point(float const _x, float const _y) : x(_x),y(_y)
{}

Point::Point(const Point &to_copy)
{
    *this = to_copy;
}
Point::~Point(){}

Point& Point::operator=(Point &original)
{
   (void)original; 
    return *this;
}

const Point& Point::operator=(const Point &original)
{
	(void)original; 
	return *this;
}

float	Point::getX(void) const
{
	return (this->x.toFloat());
}

float	Point::getY(void) const
{
	return (this->y.toFloat());
}

std::ostream& operator<<(std::ostream &os, Point const &obj)
{
	os << "(" << obj.getX() << "," << obj.getY() << ")";
	return (os);
}