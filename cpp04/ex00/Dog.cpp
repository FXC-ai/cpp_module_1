#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(Dog const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

Dog::Dog(Dog const &src)
{
	*this = src;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf !!" << std::endl;
}