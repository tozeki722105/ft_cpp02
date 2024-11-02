#include "Fixed.hpp"

int main()
{
	Fixed       a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl << std::endl;

	Fixed c(Fixed(1.0f));
	Fixed d(Fixed(2));
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << Fixed::max(d, c) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl << std::endl;

	Fixed e(Fixed(1.23f));
	std::cout << (c == e.toInt()) << std::endl;
	std::cout << (c != e) << std::endl;
	std::cout << (c < e) << std::endl;
	std::cout << (e > c) << std::endl;
	std::cout << (c <= e.toInt()) << std::endl;
	std::cout << (c >= e.toInt()) << std::endl;
}
