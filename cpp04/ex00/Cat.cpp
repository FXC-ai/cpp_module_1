#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

Cat::Cat(Cat const &src)
{
	*this = src;
}

void Cat::makeSound() const
{
	std::cout << "Miaow Miaow !!" << std::endl;
}