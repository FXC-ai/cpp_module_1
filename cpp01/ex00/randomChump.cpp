#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	newZomb(name);
	newZomb.announce();
}