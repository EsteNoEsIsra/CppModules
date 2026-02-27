#ifndef FIXED_H
#define FIXED_H

#pragma once
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &to_copy)
    Fixed &operator=(const Fixed &original)
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    

private:
    int value;
    static const int bits = 8;
};

#endif