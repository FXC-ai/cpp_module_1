#include "Fixed.hpp"


int main(void) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n";

	std::cout << "6 opérateurs de comparaisons" << std::endl;
	Fixed c(21);
	Fixed d(42);
	std::cout << "c = " << c << " d = " << d <<std::endl;
	std::cout << "c < d : " << (c < d) <<std::endl;
	std::cout << "c > d : " << (c > d) <<std::endl;
	std::cout << "c <= d : " << (c <= d) <<std::endl;
	std::cout << "c >= d : " << (c >= d) <<std::endl;
	std::cout << "c == d : " << (c == d) <<std::endl;
	std::cout << "c != d : " << (c != d) <<std::endl;

	std::cout << "\n";

	std::cout << "4 opérateurs de arithmetique" << std::endl;
	Fixed e(21.21f);
	Fixed f(42.42f);
	std::cout << "e = " << e << " f = " << f <<std::endl;
	std::cout << "e + f = " << e + f <<std::endl;
	std::cout << "e - f = " << e - f <<std::endl;
	std::cout << "e * f = " << e * f <<std::endl;
	std::cout << "e / f = " << e / f <<std::endl;

	std::cout << "\n";

	std::cout << "4 opérateurs d incrementation et de decrementation" << std::endl;
	Fixed g(1);
	Fixed h(1);
	std::cout << "g = " << g <<std::endl;
	std::cout << "++g = " << ++g <<std::endl;
	std::cout << "g++ = " << g++ <<std::endl;
	std::cout << "g = " << g <<std::endl;
	std::cout << "\n";
	std::cout << "h = " << h <<std::endl;
	std::cout << "--h = " << --h <<std::endl;
	std::cout << "h-- = " << h-- <<std::endl;
	std::cout << "h = " << h <<std::endl;

	std::cout << "\n";

	std::cout << "Fonctions statiques min et max" <<std::endl;
	Fixed i(42.1f);
	Fixed j(i + 1);
	std::cout << "i = " << i << " j = " << j <<std::endl;
	std::cout << "min(i,j) = " << Fixed::min(i,j) <<std::endl;
	std::cout << "max(i,j) = " << Fixed::max(i,j) <<std::endl;

	return (0);
}