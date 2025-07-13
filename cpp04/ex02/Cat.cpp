#include "Cat.hpp"

Cat::Cat() : A_Animal("Cat")
{
	this->_brain = new Brain;
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(Cat const &rhs)
{
	*(this->_brain) = *(rhs.getBrain());
	this->_type = rhs.getType();

	return *this;
}

Cat::Cat(Cat const &src)
{
	this->_brain = new Brain;
	*this = src;
	std::cout << "Cat copy constructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaow Miaow !!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}