#include "Fixed.hpp"

Fixed::Fixed() : _RawBits(0){}

Fixed::Fixed(int const n)
{
	this->_RawBits = (n << this->_IndComma);
}

Fixed::Fixed(float const n)
{
	this->_RawBits = static_cast<int>(roundf(n*(1 << this->_IndComma)));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_RawBits) / (1 << this->_IndComma);
}

int Fixed::toInt(void) const
{
	return (this->_RawBits >> _IndComma);
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(){}

int	Fixed::getRawBits() const
{
	return this->_RawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	this->_RawBits = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs)
{
	return this->_RawBits > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const &rhs)
{
	return this->_RawBits < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	return this->_RawBits >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	return this->_RawBits <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const &rhs)
{
	return this->_RawBits == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	return this->_RawBits != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	Fixed result;
	int RawBits;

	RawBits = this->_RawBits + rhs.getRawBits();
	result.setRawBits(RawBits);

	return result;
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	Fixed result;
	int RawBits;

	RawBits = this->_RawBits - rhs.getRawBits();
	result.setRawBits(RawBits);

	return result;
}


Fixed	Fixed::operator*(Fixed const &rhs)
{
	Fixed	result;
	int		RawBits;

	RawBits = (this->_RawBits * rhs.getRawBits()) / (1 << _IndComma);
	result.setRawBits(RawBits);

	return result;
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	Fixed result(this->toFloat() / rhs.toFloat());
	return result;
}

Fixed&	Fixed::operator++()
{
	this->_RawBits++;
	return *this;	
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_RawBits++;
	return temp;
}

Fixed&	Fixed::operator--()
{
	this->_RawBits--;
	return *this;	
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_RawBits--;
	return temp;
}


Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	return b;
}

std::ostream& operator<<(std::ostream& o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

