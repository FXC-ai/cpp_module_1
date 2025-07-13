#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string const type);
		Animal& operator=(Animal const &rhs);
		Animal(Animal const &src);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;

	protected :
		std::string _type;
};

#endif