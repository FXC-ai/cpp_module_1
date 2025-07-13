#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &src);

		FragTrap& operator=(FragTrap const &rhs);

		void attack(const std::string& target);
		
		void highFivesGuys(void);
};

#endif