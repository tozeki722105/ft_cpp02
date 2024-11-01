#include "Fixed.hpp"

int main()
{
	Fixed a;
	std::cout << '\n';

	Fixed b(a);
	std::cout << '\n';

	Fixed c;
	c = b;
	std::cout << '\n';

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}
