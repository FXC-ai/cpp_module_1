#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &src);

		ClapTrap(std::string name, unsigned int HitPoints, unsigned int EnergyPoints, unsigned int AttackDamage);

		ClapTrap& operator=(ClapTrap const &rhs);

		std::string	 getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string				_name;
		unsigned int			_HitPoints;
		unsigned int			_EnergyPoints;
		unsigned int			_AttackDamage;
	
};

#endif