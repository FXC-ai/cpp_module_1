#include "ClapTrap.hpp"

int main()
{
	std::cout << "\033[1;31mAppel du constructeur par defaut; :\033[0m" << std::endl;
	ClapTrap CP_unamed;
	std::cout << "\n";

	std::cout << "\033[1;31mAppel du constructeur ClapTrap(std::string name); :\033[0m" << std::endl;
	ClapTrap CP_Roger("Roger");
	ClapTrap CP_Stan("Stan");
	std::cout << "\n";

	std::cout << "\033[1;31mAppel du constructeur de copie :\033[0m" << std::endl;
	ClapTrap CP_copyRoger(CP_Roger);
	std::cout << "\n";

	std::cout << "\033[1;31mRoger attaque Stan :\033[0m" << std::endl;
	for (int i = 0; i < 11; ++i)
	{
		CP_Roger.attack("Stan");
		CP_Stan.takeDamage(CP_Roger.getAttackDamage());
		std::cout << "\n";
	}

	std::cout << "\033[1;31mTest fonction void takeDamage(unsigned int amount); :\033[0m" << std::endl;
	CP_Stan.takeDamage(8);
	std::cout << "\n";

	std::cout << "\033[1;31mTest fonction void beRepaired(unsigned int amount); :\033[0m" << std::endl;
	CP_Stan.beRepaired(2);

	std::cout << "\n";
	return 0;
}