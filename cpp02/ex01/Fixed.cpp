#include "Fixed.hpp"

Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	this->_RawBits = (n << this->_IndComma);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n)
{
	/*
		Dans le main on instacie un objet ainsi : Fixed c(42.42)
		Pour obtenir la valeur de RawBit :
			1) On calcule le_float_en_parametre * 256 = 42.42 * 256 = 10859.52
			2) On caste 10859.52 dans RawBit, il va stocker 10859
			MAIS ! Pour plus de precision il serait préférable d'arrondir avant de 
			caster dans in int.
			Du coup...
			2) roundf(10859.52) renvoie 10860
			3) On caste 10860 dans un RawBit
	*/

	this->_RawBits = static_cast<int>(roundf(n*(1 << this->_IndComma)));
	std::cout << "Float constructor called" << std::endl;

}

float Fixed::toFloat(void) const
{
	/*
		Algo :
			1) On convertit RawBit en un float
			2) On divise ce float par 256 pour retrouver la valeur initiale
		C++ se charge de donner à la mantisse et à l'exposant les bonnes valeurs.
	*/

	return static_cast<float>(this->_RawBits) / (1 << this->_IndComma);
}

int Fixed::toInt(void) const
{
	return (this->_RawBits >> _IndComma);
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	(void) this->_IndComma;
	return this->_RawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_RawBits = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}