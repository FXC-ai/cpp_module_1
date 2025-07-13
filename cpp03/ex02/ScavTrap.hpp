#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);

		ScavTrap& operator=(ScavTrap const &rhs);

		void attack(const std::string& target);
		
		void guardGate();
};

#endif