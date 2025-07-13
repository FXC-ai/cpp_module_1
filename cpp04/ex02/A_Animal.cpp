#include "A_Animal.hpp"

A_Animal::A_Animal() : _type("none")
{
	std::cout << "Default A_Animal constructor called." << std::endl;
}

A_Animal::A_Animal(std::string const type) : _type(type)
{
	std::cout << "A_Animal constructor called : " << this->_type <<std::endl;
}

std::string A_Animal::getType() const
{
	return this->_type;
}

A_Animal& A_Animal::operator=(A_Animal const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

A_Animal::A_Animal(A_Animal const &src)
{
	*this = src;
	std::cout << "Copy A_Animal constructor called." << std::endl;
}

A_Animal::~A_Animal()
{
	std::cout << "A_Animal destructor called." << std::endl;
}
