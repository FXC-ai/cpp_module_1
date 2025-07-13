#include "Zombie.hpp"
#include <string>
#include <iostream>


Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde;
	int		i;

	i = 0;
	horde = new Zombie[N];

	for (i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}

	return horde;
}