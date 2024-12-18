#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
	int              rawBits;
	const static int FRACTIONAL_BITS = 8;
	const static int FRACTAL_MASK = (1 << FRACTIONAL_BITS) - 1;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &rhs);
	float  toFloat(void) const;
	int    toInt(void) const;
	int    getRawBits(void) const;
	void   setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif