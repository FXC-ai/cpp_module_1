#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unamed", 100, 50,20)
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called. Name = " << this->_name <<std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src)
{
	*this = src;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can not attack anymore. He has not enough Hit Points." << std::endl;
	}
	else if (this->_EnergyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can not attack anymore. He has not enough Energy Points." << std::endl;
	}
	else
	{
		--this->_EnergyPoints;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" <<std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap : " << this->_name << " is in Gate Keeper mode." <<std::endl;
}