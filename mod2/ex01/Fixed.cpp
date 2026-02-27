
#include "Fixed.hpp"


Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std:: endl;
}

Fixed::Fixed(const int inInt): value(inInt * (1 << Fixed::bits)) {
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float inFloat) : value( roundf(inFloat * (1 << Fixed::bits))) {
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() member function called" << std::endl;// coment
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
 {
	return (float)this->value / (float)(1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
	return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}