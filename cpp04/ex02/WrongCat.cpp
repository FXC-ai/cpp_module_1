#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	this->_brain = new Brain;
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	delete this->_brain;
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs)
{
	*(this->_brain) = *(rhs.getBrain());
	this->_type = rhs.getType();
	return *this;
}

WrongCat::WrongCat(WrongCat const &src)
{
	this->_brain = new Brain;
	*this = src;
	std::cout << "Cat copy constructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaow Miaow !!" << std::endl;
}

Brain* WrongCat::getBrain() const
{
	return this->_brain;
}