#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	{
		std::cout << "\033[1;32mTests pour Animal Dog Cat\033[0m" << std::endl;
		std::cout << "\033[1;34mInstanciations :\033[0m" << std::endl;
		const Animal* meta = new Animal();
		std::cout << "\n";

		const Animal* j = new Dog();
		std::cout << "\n";

		const Animal* i = new Cat();
		std::cout << "\n";

		std::cout << "\033[1;34mTests :\033[0m" << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "-----------------------------------------------\n";
	{
		std::cout << "\033[1;32mTests pour WrongAnimal WrongCat\033[0m" << std::endl;
		std::cout << "\033[1;34mInstanciations :\033[0m" << std::endl;

		const WrongAnimal* meta = new WrongAnimal();
		std::cout << "\n";

		const WrongAnimal* i = new WrongCat();
		std::cout << "\n";

		std::cout << "\033[1;34mTests :\033[0m" << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}

	return 0;
}