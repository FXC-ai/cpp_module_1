#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\033[1;31mTests constructeurs FragTrap :\033[0m" << std::endl;
	std::cout << "\n";

	std::cout << "\033[1;32mPar defaut :\033[0m" << std::endl;
	FragTrap FG_unamed;
	std::cout << "\n";
	
	std::cout << "\033[1;32mTest constructeur FragTrap(std::string name) :\033[0m" << std::endl;
	FragTrap FG_Teddy("Teddy");
	std::cout << "\n";
	FragTrap FG_Naoya("Naoya");
	std::cout << "\n";

	std::cout << "\033[1;32mTest constructeur FragTrap(FragTrap &src); \033[0m" << std::endl;
	FragTrap FG_copyNaoya(FG_Naoya);
	std::cout << "\n";

	std::cout << "\033[1;31mValeurs par defaut des attributs :\033[0m" << std::endl;
	std::cout << "Teddy : Hit Points = " << FG_Teddy.getHitPoints() <<std::endl\
			  << "Teddy : Energy Points = "<< FG_Teddy.getEnergyPoints() <<std::endl\
			  << "Teddy : Attack Damage = "<< FG_Teddy.getAttackDamage() <<std::endl;
	std::cout << "\n";

	std::cout << "\033[1;31mTest fonction void highFivesGuys(void); \033[0m" << std::endl;
	FG_unamed.highFivesGuys();
	FG_Teddy.highFivesGuys();
	FG_Naoya.highFivesGuys();
	FG_copyNaoya.highFivesGuys();
	std::cout << "\n";

	std::cout << "\033[1;31mTests fonctions attack et takeDamage\033[0m" << std::endl;
	FG_Teddy.attack(FG_Naoya.getName());
	FG_Naoya.takeDamage(FG_Teddy.getAttackDamage());
	std::cout << "\n";


	std::cout << "\033[1;31mCheck HP de FG_Naoya et FG_copyNaoya :\033[0m" << std::endl;
	std::cout << "      Naoya : " << FG_Naoya.getHitPoints() << std::endl;
	std::cout << "Copie Naoya : " << FG_copyNaoya.getHitPoints() << std::endl;
	std::cout << "\n";


	std::cout << "\033[1;31mDestruction des instances :\033[0m" << std::endl;

	// FragTrap FG_Naoya("Naoya");




	// CP_unamed.attack(FG_Teddy.getName());
	// FG_Teddy.takeDamage(CP_unamed.getAttackDamage());
	// std::cout << "\n";

	// FragTrap FG_Naoya2(FG_Naoya);
	// std::cout << "\n";


	// std::cout << "\n";

	// std::cout << "Mais Naoya2 a toujours tous ses HP : " << FG_Naoya2.getHitPoints() <<std::endl;
	
	// FG_Naoya.attack(CP_unamed.getName());
	// CP_unamed.takeDamage(FG_Naoya.getAttackDamage());

	// std::cout << "\n";

	return 0;
}