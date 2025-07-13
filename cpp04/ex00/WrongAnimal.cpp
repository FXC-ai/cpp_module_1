#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("none")
{
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{
	std::cout << "WrongAnimal constructor called : " << this->_type <<std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy WrongAnimal constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "No sound" <<std::endl;
}