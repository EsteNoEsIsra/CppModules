#ifndef FIXED_H
#define FIXED_H

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:

    Fixed();
 
    Fixed(const int inInt);
	Fixed(const float inFloat);

    Fixed(const Fixed &to_copy)
    Fixed &operator=(const Fixed &original)

    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
	int toInt(void) const;

private:
    int value;
    static const int bits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif