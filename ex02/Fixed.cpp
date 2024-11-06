#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const int n) : rawBits(n << FRACTIONAL_BITS) {}

Fixed::Fixed(const float n) : rawBits(static_cast<int>(roundf(n * (1 << FRACTIONAL_BITS)))) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) : rawBits(other.getRawBits()) {}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return (*this);
	this->setRawBits(other.getRawBits());
	return (*this);
}
int Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->rawBits < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->rawBits > rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (this->rawBits <= rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->rawBits >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (this->rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

// rhs.getRawBits() == 0 -> crash
Fixed Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->rawBits += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->rawBits += 1;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->rawBits -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->rawBits -= 1;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
