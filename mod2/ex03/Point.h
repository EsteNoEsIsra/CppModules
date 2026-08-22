#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
    public:
        Point();
        Point(const Point& to_copy);
        Point &operator=(Point& original);
        ~Point();

        Point(float const _x, float const _y);
        const Point &operator=(const Point& original);
        float	getX(void) const;
	    float	getY(void) const;
    private:
        Fixed const x;
        Fixed const y;
};

std::ostream& operator<<(std::ostream& os, const Point &obj);

#endif