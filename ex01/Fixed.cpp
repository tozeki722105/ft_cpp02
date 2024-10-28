#include "Fixed.hpp"

Fixed::Fixed() : raw_values(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : raw_values(n << fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : raw_values(static_cast<int>(std::roundf(n * (1 << fractional_bits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->setRawBits(fixed.getRawBits());
	*this = fixed;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_values);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->raw_values = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->raw_values) / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->raw_values >> this->fractional_bits);
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}