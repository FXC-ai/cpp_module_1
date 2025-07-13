#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain& operator=(Brain const &src);
		Brain(Brain const &rhs);
		~Brain();

		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string const &idea);
};

#endif