#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unamed"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, uint HitPoints, uint EnergyPoints, uint AttackDamage) : _name(name), _HitPoints(HitPoints), _EnergyPoints(EnergyPoints), _AttackDamage(AttackDamage)
{
	std::cout << "ClapTrap full constructor called. Name = "<< this->_name << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	return *this;
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return this->_HitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->_EnergyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->_AttackDamage;
}





void ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can not attack anymore. He has not enough Hit Points." << std::endl;
	}
	else if (this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can not attack anymore. He has not enough Energy Points." << std::endl;
	}
	else
	{
		--this->_EnergyPoints;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" <<std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		std::cout << this->_name << " has 0 Hit point. He can not take damage anymore." << std::endl;
	}
	else if (this->_HitPoints >= amount)
	{
		this->_HitPoints -= amount;
		std::cout << this->_name << " took " << amount << " of damage.";
		std::cout << " He has " << this->_HitPoints << " Hit points left." <<std::endl;
	}
	else if (this->_HitPoints < amount)
	{
		this->_HitPoints = 0;
		std::cout << this->_name << " took " << amount << " of damage.";
		std::cout << " He has " << this->_HitPoints << " Hit points left." <<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_HitPoints += amount;
	std::cout << this->_name << " get " << amount << " of new Hit points." <<std::endl;
}