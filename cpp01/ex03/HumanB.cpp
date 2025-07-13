#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB (std::string const name) : _name(name) 
{
	this->_weapon = NULL;

}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon; // Dereferencement necessaire CAR une reference est un pointeur déréférencé par defaut !!!
}

void	HumanB::attack()
{
	if (this->_weapon != NULL)
	{
		std::cout << this->_name + " attacks with their " + this->_weapon->getType() << std::endl;
	}
}