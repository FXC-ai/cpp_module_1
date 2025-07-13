#include "Dog.hpp"

Dog::Dog() : A_Animal("Dog")
{
	this->_brain = new Brain;
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(Dog const &rhs)
{
	*(this->_brain) = *(rhs.getBrain());
	this->_type = rhs.getType();

	return *this;
}

Dog::Dog(Dog const &src)
{
	this->_brain = new Brain;
	*this = src;
	std::cout << "Dog copy constructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf !!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}