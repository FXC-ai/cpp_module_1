#include "Zombie.hpp"
#include <string>
#include <iostream>

int main ()
{
	
	Zombie	*horde;
	int		i(0);
	int		max(42);

	horde = zombieHorde(max, "FX");

	for (i = 0; i < max; i++)
	{
		std::cout << i << " ";
		horde[i].announce();
	}

	delete [] horde;

	return 0;
}