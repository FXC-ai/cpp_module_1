#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string const	_name;
		Weapon&				_type;

	public:
		HumanA(std::string const name, Weapon& type);
		~HumanA();
		void	attack();
};

#endif