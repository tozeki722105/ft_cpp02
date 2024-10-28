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
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif