#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int              rawBits;
	const static int FRACTIONAL_BITS = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &rhs);
	int    getRawBits(void) const;
	void   setRawBits(int const raw);
};

#endif