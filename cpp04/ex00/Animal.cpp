#include "Animal.hpp"

Animal::Animal() : _type("none")
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(std::string const type) : _type(type)
{
	std::cout << "Animal constructor called : " << this->_type <<std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

Animal& Animal::operator=(Animal const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Copy Animal constructor called." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "No sound" <<std::endl;
}