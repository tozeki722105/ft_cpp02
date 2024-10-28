#include "Fixed.hpp"

Fixed::Fixed() : raw_values(0) {}

Fixed::Fixed(const int n) : raw_values(n << fractional_bits) {}

Fixed::Fixed(const float n) : raw_values(static_cast<int>(std::roundf(n * (1 << fractional_bits)))) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

int Fixed::getRawBits(void) const
{
	return (this->raw_values);
}

void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->raw_values < rhs.getRawBits());
}
bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->raw_values > rhs.getRawBits());
}
bool Fixed::operator<=(const Fixed& rhs) const
{
	return (this->raw_values <= rhs.getRawBits());
}
bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->raw_values >= rhs.getRawBits());
}
bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->raw_values == rhs.getRawBits());
}
bool Fixed::operator!=(const Fixed& rhs) const
{
	return (this->raw_values != rhs.getRawBits());
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

Fixed Fixed::operator++()
{
	this->raw_values += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->raw_values += 1;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->raw_values -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->raw_values -= 1;
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

Fixed &Fixed::max(Fixed &a, Fixed &b)
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