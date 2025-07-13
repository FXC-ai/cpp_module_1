#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("unamed", 100, 100,30)
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called. Name = " << this->_name <<std::endl;
}

FragTrap::FragTrap(FragTrap &src)
{
	*this = src;
	std::cout << "FragTrap copy constructor called." <<std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can not attack anymore. He has not enough Hit Points." << std::endl;
	}
	else if (this->_EnergyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can not attack anymore. He has not enough Energy Points." << std::endl;
	}
	else
	{
		--this->_EnergyPoints;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" <<std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : " << this->_name << " do a high five !" <<std::endl;
}