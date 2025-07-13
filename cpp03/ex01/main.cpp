#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\033[1;31mTests constructeurs ScavTrap\033[0m" << std::endl;
	ScavTrap	SC_Kilian("Kilian");
	std::cout << "\n";
	ScavTrap	SC_Francois("Francois");
	std::cout << "\n";

	ScavTrap	SC_copyFrancois(SC_Francois);	

	std::cout << "\n";

	std::cout << "\033[1;31mValeurs par defaut des attributs :\033[0m" << std::endl;
	std::cout << "Kilian : Hit Points = " << SC_Kilian.getHitPoints() <<std::endl\
			  << "Kilian : Energy Points = "<< SC_Kilian.getEnergyPoints() <<std::endl\
			  << "Kilian : Attack Damage = "<< SC_Kilian.getAttackDamage() <<std::endl;
	std::cout << "\n";


	std::cout << "\033[1;31mKilian va tuer Francois :\033[0m" << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		SC_Kilian.attack(SC_Francois.getName());
		SC_Francois.takeDamage(SC_Kilian.getAttackDamage());
		std::cout << "\n";
	}

	std::cout << "\033[1;31mTest fonction void guardGate();\033[0m" << std::endl;
	SC_Kilian.guardGate();
	std::cout << "\n";

	std::cout << "\033[1;31mDestruction des instances :\033[0m" << std::endl;

	return 0;
}