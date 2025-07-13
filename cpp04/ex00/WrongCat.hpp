#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat& operator=(WrongCat const &rhs);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat();

		void		makeSound() const;
};

#endif