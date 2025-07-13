#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>

class A_Animal
{
	public:
		A_Animal();
		A_Animal(std::string const type);
		A_Animal& operator=(A_Animal const &rhs);
		A_Animal(A_Animal const &src);
		virtual ~A_Animal();

		std::string		getType() const;
		virtual void	makeSound() const = 0;

	protected :
		std::string		_type;	
};

#endif