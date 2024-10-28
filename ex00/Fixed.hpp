#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int raw_values;
	const static int fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed &fixed);
	Fixed& operator=(const Fixed &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif