#ifndef CAT_HPP
# define CAT_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal
{
	public:
		Cat();
		Cat& operator=(Cat const &rhs);
		Cat(Cat const &src);
		virtual ~Cat();
		
		Brain*				getBrain() const;
		virtual void		makeSound() const;

	private :
		Brain*	_brain;
};

#endif