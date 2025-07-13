#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called. Name = " << this->_name <<std::endl;
}

ClapTrap::ClapTrap(std::string name, uint HitPoints, uint EnergyPoints, uint AttackDamage) : _name(name), _hitPoints(HitPoints), _energyPoints(EnergyPoints), _attackDamage(AttackDamage)
{
	std::cout << "ClapTrap full constructor called. Name = "<< this->_name << std::endl;
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return *this;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap copy constructor called." <<std::endl;
	//return this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can not attack anymore. He has not enough Hit Points." << std::endl;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can not attack anymore. He has not enough Energy Points." << std::endl;
	}
	else
	{
		--this->_energyPoints;

		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" <<std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has 0 Hit point. He can not take damage anymore." << std::endl;
	}
	else if (this->_hitPoints >= amount)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage.";
		std::cout << " He has " << this->_hitPoints << " Hit points left." <<std::endl;
	}
	else if (this->_hitPoints < amount)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage.";
		std::cout << " He has " << this->_hitPoints << " Hit points left." <<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " get " << amount << " of new points." <<std::endl;
}