#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat& operator=(Cat const &rhs);
		Cat(Cat const &src);
		virtual ~Cat();

		virtual void		makeSound() const;
};

#endif