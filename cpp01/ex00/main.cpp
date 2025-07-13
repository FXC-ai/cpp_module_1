#include "Zombie.hpp"

int main ()
{
	Zombie	ZombieStack("ZStack");
	Zombie	*ZombieHeap = newZombie("ZHeap");
	std::cout << std::endl;

	ZombieStack.announce();
	ZombieHeap->announce();
	std::cout << std::endl;
	
	randomChump("Zrandom");
	std::cout << std::endl;
	
	delete ZombieHeap;

	return 0;
}