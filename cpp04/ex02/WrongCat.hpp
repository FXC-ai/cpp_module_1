#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat& operator=(WrongCat const &rhs);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat();

		Brain*				getBrain() const;
		void				makeSound() const;

	private :
		Brain*	_brain;
};

#endif