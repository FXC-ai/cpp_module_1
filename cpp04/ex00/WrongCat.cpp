#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaow Miaow !!" << std::endl;
}