#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    // Fixed a(0);
    // Fixed b(5.05f);
    // Fixed c(2);

    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;


    // std::cout << "2 + 5.05 = " << b + c << std::endl;
    // std::cout << "5.05 / 2 = " << (b / c) <<  std::endl;
    // std::cout << "min 0.0078125 , 5.05 = " << Fixed::min(a , b) << std::endl;
    // std::cout << "max 0.0078125 , 5.05 = "<< Fixed::max(a , b) << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
