#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int raw_values;
	const static int fractional_bits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed(const Fixed &fixed);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed &rhs);
	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif