#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog& operator=(Dog const &rhs);
		Dog(Dog const &src);
		virtual ~Dog();

		Brain*				getBrain() const;
		virtual void		makeSound() const;

	private :
		Brain*	_brain;
};

#endif