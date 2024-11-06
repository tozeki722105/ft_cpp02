#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : rawBits(n << FRACTIONAL_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : rawBits(static_cast<int>(roundf(n * (1 << FRACTIONAL_BITS))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : rawBits(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &othrer)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &othrer)
		return (*this);
	this->setRawBits(othrer.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / (1 << this->FRACTIONAL_BITS));
}

int Fixed::toInt(void) const
{
	int fractalPart = rawBits & FRACTAL_MASK;
	if (rawBits < 0 && fractalPart)
		return ((rawBits >> FRACTIONAL_BITS) + 1);
	return (rawBits >> FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
